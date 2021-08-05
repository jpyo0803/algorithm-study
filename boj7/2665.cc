// 미로만들기
// https://www.acmicpc.net/problem/2665

#include <stdio.h>

#include <queue>
#include <utility>

using namespace std;

int N;

char line[55];
bool map[50][50];
int dist[50][50];

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool CanGo(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }

int Solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = 987654321;
    }
  }
  priority_queue<pair<int, pair<int, int>>> pq;
  pq.emplace(0, make_pair(0, 0));
  dist[0][0] = 0;

  while (!pq.empty()) {
    int cost = -pq.top().first;
    auto p = pq.top().second;
    pq.pop();

    if (cost > dist[p.first][p.second]) continue;

    for (int i = 0; i < 4; i++) {
      int ni = p.first + d[i][0];
      int nj = p.second + d[i][1];
      if (!CanGo(ni, nj)) continue;

      int next_cost = cost + !map[ni][nj];
      if (next_cost < dist[ni][nj]) {
        dist[ni][nj] = next_cost;
        pq.emplace(-next_cost, make_pair(ni, nj));
      }
    }
  }
  return dist[N - 1][N - 1];
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", line);
    for (int j = 0; j < N; j++) {
      map[i][j] = line[j] == '1' ? true : false;
    }
  }

  printf("%d\n", Solve());

  return 0;
}
