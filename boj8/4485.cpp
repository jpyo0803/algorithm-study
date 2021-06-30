// 녹색 옷 입은 애가 젤다지?
// https://www.acmicpc.net/problem/4485

#include <stdio.h>

#include <queue>
#include <utility>

using namespace std;

constexpr int kInf = 987654321;

int N;

int cost_map[125][125];
int dist[125][125];

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void PrintAnswer(int nth, int ans) { printf("Problem %d: %d\n", nth, ans); }

bool InRange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }

int Solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = kInf;
    }
  }

  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push(make_pair(-cost_map[0][0], make_pair(0, 0)));
  dist[0][0] = cost_map[0][0];

  while (!pq.empty()) {
    int i = pq.top().second.first, j = pq.top().second.second;
    int cost = -pq.top().first;
    pq.pop();

    for (int k = 0; k < 4; ++k) {
      int ni = i + d[k][0], nj = j + d[k][1];
      if (!InRange(ni, nj)) continue;
      int next_cost = cost + cost_map[ni][nj];
      if (next_cost < dist[ni][nj]) {
        dist[ni][nj] = next_cost;
        pq.push(make_pair(-next_cost, make_pair(ni, nj)));
      }
    }
  }
  return dist[N - 1][N - 1];
}

int main() {
  scanf("%d", &N);
  int t = 1;
  while (N != 0) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        scanf("%d", &cost_map[i][j]);
      }
    }
    PrintAnswer(t, Solve());
    t++;
    scanf("%d", &N);
  }

  return 0;
}
