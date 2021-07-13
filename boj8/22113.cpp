// 창영이와 버스
// https://www.acmicpc.net/problem/22113

#include <stdio.h>

int N, M;
int bus_seq[100];
int transfer_fee[100][100];

int Solve() {
  int total_cost = 0;
  for (int i = 0; i < M - 1; ++i) {
    int u = bus_seq[i] - 1;
    int v = bus_seq[i + 1] - 1;
    total_cost += transfer_fee[u][v];
  }
  return total_cost;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int m = 0; m < M; ++m) scanf("%d", &bus_seq[m]);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", &transfer_fee[i][j]);
    }
  }

  printf("%d\n", Solve());
  return 0;
}
