// 저울
// https://www.acmicpc.net/problem/10159

#include <stdio.h>

int N, M, a, b;

bool connected[101][101];

void Solve() {
  for (int k = 1; k <= N; k++) {
    for (int u = 1; u <= N; u++) {
      if (!connected[u][k] || u == k) continue;
      for (int v = 1; v <= N; v++) {
        if (k == v) continue;
        if (connected[u][k] && connected[k][v]) {
          connected[u][v] = true;
        }
      }
    }
  }

  for (int u = 1; u <= N; u++) {
    int count = 0;
    for (int v = 1; v <= N; v++) {
      if (u == v) continue;
      if (!connected[u][v] && !connected[v][u]) count++;
    }
    printf("%d\n", count);
  }
}

int main() {
  scanf("%d%d", &N, &M);

  for (int m = 0; m < M; m++) {
    scanf("%d%d", &a, &b);
    connected[a][b] = true;
  }

  Solve();
  return 0;
}
