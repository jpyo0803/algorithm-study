// 오민식의 고민
// https://www.acmicpc.net/problem/1219

#include <stdio.h>

#include <queue>
#include <utility>
#include <vector>

using namespace std;

constexpr long long kInf = 987654321654321;

int N, M, S, T, U, V;
long long C;

vector<pair<int, long long>> adj[100];
;
long long dist[100];
long long earning[100];
bool visited[100];

void Solve(int S, int T) {
  for (int i = 0; i < N; i++) dist[i] = kInf;
  dist[S] = -earning[S];

  queue<int> que;

  bool updated;
  for (int i = 0; i < N; i++) {
    updated = false;
    for (int u = 0; u < N; u++) {
      if (dist[u] == kInf) continue;
      for (auto& edge : adj[u]) {
        int v = edge.first;
        long long next_dist = dist[u] + edge.second - earning[v];
        if (next_dist < dist[v]) {
          dist[v] = next_dist;
          updated = true;
          if (i == N - 1) que.push(u);
        }
      }
    }
    if (!updated) break;
  }

  bool reachable = false;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (u == T) {
      reachable = true;
      break;
    }

    for (auto& edge : adj[u]) {
      int v = edge.first;
      if (visited[v]) continue;
      que.push(v);
      visited[v] = true;
    }
  }

  if (dist[T] == kInf)
    printf("gg\n");
  else if (updated && reachable)
    printf("Gee\n");
  else
    printf("%lld\n", -dist[T]);
}

int main() {
  scanf("%d%d%d%d", &N, &S, &T, &M);
  for (int m = 0; m < M; m++) {
    scanf("%d%d%lld", &U, &V, &C);
    adj[U].emplace_back(V, C);
  }
  for (int n = 0; n < N; n++) scanf("%lld", &earning[n]);

  Solve(S, T);
  return 0;
}
