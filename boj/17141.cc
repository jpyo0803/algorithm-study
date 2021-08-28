//
// Research center 2
// Problem : https://www.acmicpc.net/problem/17141
//

#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE{50};
const int INF{100000000};
int N, M, possible_count;
int floor[MAX_SIZE][MAX_SIZE];
int level[MAX_SIZE][MAX_SIZE];

vector<pair<int, int>> candidate, frontier, next_frontier;
int chosen[10];
int ans;

int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int solve(int chosen[], int m) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      level[i][j] = -1;
    }
  }

  frontier.clear();
  for (int i = 0; i < m; i++) {
    frontier.push_back(candidate[chosen[i]]);
    level[candidate[chosen[i]].first][candidate[chosen[i]].second] = 0;
  }

  int day{0};
  int left_count = possible_count - m;
  while (!frontier.empty()) {
    next_frontier.clear();
    day += 1;
    for (auto virus : frontier) {
      for (int i = 0; i < 4; i++) {
        int nr{virus.first + d[i][0]};
        int nc{virus.second + d[i][1]};

        if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
          if (floor[nr][nc] != 1 && level[nr][nc] == -1) {
            next_frontier.emplace_back(nr, nc);
            level[nr][nc] = day;
            left_count -= 1;
          }
        }
      }
    }
    swap(frontier, next_frontier);
  }

  if (left_count > 0) return INF;

  return day;
}

void comb(int chosen[], int n, int m, int last_val, int curr_index) {
  if (curr_index == m) {
    int ret = solve(chosen, m);
    if (ret < ans) {
      ans = ret;
    }
  } else {
    for (int i = last_val + 1; i < n; i++) {
      chosen[curr_index] = i;
      comb(chosen, n, m, i, curr_index + 1);
    }
  }
}
int main() {
  cin >> N >> M;
  possible_count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> floor[i][j];
      if (floor[i][j] != 1) {
        if (floor[i][j] == 2) {
          candidate.emplace_back(i, j);
        }
        possible_count += 1;
      }
    }
  }

  ans = INF;
  comb(chosen, candidate.size(), M, -1, 0);

  if (ans == INF)
    cout << -1;
  else
    cout << ans - 1;
  return 0;
}
