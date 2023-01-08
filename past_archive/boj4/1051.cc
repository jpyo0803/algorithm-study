//
// Number Squre
// Link: https://www.acmicpc.net/problem/1051
//

#include <cstdint>
#include <cstdio>

constexpr int8_t kMax = 50;

int8_t Max(int8_t x, int8_t y) { return x > y ? x : y; }

int N, M, ans;
int8_t field[kMax][kMax];

void Solve(int8_t edge_length) {
  for (int8_t r = 0; r < N - edge_length; r++) {
    for (int8_t c = 0; c < M - edge_length; c++) {
      if (field[r + edge_length][c] == field[r][c] &&
          field[r][c + edge_length] == field[r][c] &&
          field[r + edge_length][c + edge_length] == field[r][c]) {
        ans = (edge_length + 1) * (edge_length + 1);
        return;
      }
    }
  }
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    char row[M + 1];
    scanf("%s", row);
    for (int8_t j = 0; j < M; j++) {
      field[i][j] = row[j] - '0';
    }
  }

  int8_t edge_length = Max(N - 1, M - 1);

  ans = -1;
  while (edge_length >= 0) {
    Solve(edge_length);
    if (ans != -1) break;
    edge_length--;
  }

  printf("%d\n", ans);

  return 0;
}