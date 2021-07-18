// 점프 게임
// https://www.acmicpc.net/problem/15558

#include <stdio.h>

#include <utility>
#include <vector>

using namespace std;

int N, K;

char map[2][100001];
bool check[2][100001];

bool Solve() {
  bool ans = false;
  vector<pair<int, int>> frontier, next;
  frontier.emplace_back(0, 0);
  check[0][0] = check[1][0] = true;

  int time = 1;
  while (!frontier.empty()) {
    next.clear();
    for (auto& u : frontier) {
      if (u.second + 1 >= N) {
        ans = true;
        break;
      } else {
        if (map[u.first][u.second + 1] == '1' &&
            !check[u.first][u.second + 1]) {
          next.emplace_back(u.first, u.second + 1);
          check[u.first][u.second + 1] = true;
        }
      }
      if (u.second - 1 >= 0) {
        if (map[u.first][u.second - 1] == '1' &&
            !check[u.first][u.second - 1]) {
          next.emplace_back(u.first, u.second - 1);
          check[u.first][u.second - 1] = true;
        }
      }
      if (u.second + K >= N) {
        ans = true;
        break;
      } else {
        int other_row = (u.first + 1) % 2;
        if (map[other_row][u.second + K] == '1' &&
            !check[other_row][u.second + K]) {
          next.emplace_back(other_row, u.second + K);
          check[other_row][u.second + K] = true;
        }
      }
    }

    if (ans) break;

    check[0][time] = check[1][time] = true;
    time++;
    swap(frontier, next);
  }
  return ans;
}

int main() {
  scanf("%d%d%s%s", &N, &K, map[0], map[1]);
  printf("%d\n", Solve());
  return 0;
}