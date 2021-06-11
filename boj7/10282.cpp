// 해킹
// https://www.acmicpc.net/problem/10282

#include <stdio.h>

#include <queue>
#include <utility>
#include <vector>

using namespace std;

constexpr int kInf = 987654321;

int T, N, D, C, A, B, S;

int dist[10001];
vector<pair<int, int>> adj[10001];

pair<int, int> Solve(int C) {
  for (int i = 1; i <= N; i++) dist[i] = kInf;

  priority_queue<pair<int, int>> pq;
  pq.emplace(0, C);
  dist[C] = 0;

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int now = pq.top().second;
    pq.pop();

    if (cost > dist[now]) continue;

    for (auto& next : adj[now]) {
      int next_cost = cost + next.second;
      if (next_cost < dist[next.first]) {
        dist[next.first] = next_cost;
        pq.emplace(-next_cost, next.first);
      }
    }
  }

  int num_infected = 0, max_time = 0;
  for (int i = 1; i <= N; i++) {
    if (dist[i] != kInf) {
      num_infected++;
      max_time = max_time < dist[i] ? dist[i] : max_time;
    }
  }
  return make_pair(num_infected, max_time);
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d%d%d", &N, &D, &C);
    for (int d = 0; d < D; d++) {
      scanf("%d%d%d", &A, &B, &S);
      adj[B].emplace_back(A, S);
    }

    auto ans = Solve(C);
    printf("%d %d\n", ans.first, ans.second);
    for (int i = 1; i <= N; i++) adj[i].clear();
  }
  return 0;
}
