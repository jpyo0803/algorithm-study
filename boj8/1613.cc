// 역사
// https://www.acmicpc.net/problem/1613

#include <stdio.h>

int N, K, a, b, S;

bool connected[401][401];

void Solve() {
  for (int k = 1; k <= N; k++) {
    for (int u = 1; u <= N; u++) {
      if (!connected[u][k]) continue;
      for (int v = 1; v <= N; v++) {
        connected[u][v] =
            connected[u][k] && connected[k][v] ? true : connected[u][v];
      }
    }
  }

  scanf("%d", &S);
  for (int s = 0; s < S; s++) {
    scanf("%d%d", &a, &b);
    if (connected[a][b])
      printf("-1\n");
    else if (connected[b][a])
      printf("1\n");
    else
      printf("0\n");
  }
}

int main() {
  scanf("%d%d", &N, &K);
  for (int k = 0; k < K; k++) {
    scanf("%d%d", &a, &b);
    connected[a][b] = true;
  }

  Solve();
  return 0;
}
