// 운동
// https://www.acmicpc.net/problem/1956

#include <stdio.h>

constexpr long long kInf = 10987654321;

int V, E, a, b;
long long c;

long long dist[401][401];

long long Min(long long x, long long y) { return x < y ? x : y; }

long long Solve() {
  for (int k = 1; k <= V; k++) {
    for (int u = 1; u <= V; u++) {
      if (dist[u][k] == kInf) continue;
      for (int v = 1; v <= V; v++) {
        if (u == v) continue;
        if (dist[k][v] == kInf) continue;
        dist[u][v] = Min(dist[u][v], dist[u][k] + dist[k][v]);
      }
    }
  }

  long long ans = kInf;
  for (int u = 1; u <= V; u++) {
    for (int v = 1; v <= V; v++) {
      if (u == v) continue;
      if (dist[u][v] == kInf || dist[v][u] == kInf) continue;
      ans = Min(ans, dist[u][v] + dist[v][u]);
    }
  }

  return (ans == kInf ? -1 : ans);
}

int main() {
  scanf("%d%d", &V, &E);

  for (int i = 1; i <= V; i++)
    for (int j = 1; j <= V; j++) dist[i][j] = i == j ? 0 : kInf;

  for (int e = 0; e < E; e++) {
    scanf("%d%d%lld", &a, &b, &c);
    dist[a][b] = c;
  }

  printf("%lld\n", Solve());
  return 0;
}
