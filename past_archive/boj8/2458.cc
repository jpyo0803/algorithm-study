// 키 순서
// https://www.acmicpc.net/problem/2458

#include <stdio.h>

int N, M, a, b;
bool connected[501][501];

int Solve() {
  for (int k = 1; k <= N; k++) {
    for (int u = 1; u <= N; u++) {
      if (!connected[u][k]) continue;
      for (int v = 1; v <= N; v++) {
        connected[u][v] =
            connected[u][k] && connected[k][v] ? true : connected[u][v];
      }
    }
  }

  int ans = 0;
  for (int u = 1; u <= N; u++) {
    int count = 0;
    for (int v = 1; v <= N; v++) {
      if (connected[u][v] || connected[v][u]) count++;
    }
    if (count == N) ans++;
  }
  return ans;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      connected[i][j] = i == j;
    }
  }

  for (int m = 0; m < M; m++) {
    scanf("%d%d", &a, &b);
    connected[a][b] = true;
  }

  printf("%d\n", Solve());
  return 0;
}
