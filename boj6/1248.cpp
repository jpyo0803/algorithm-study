// 맞춰봐
// https://www.acmicpc.net/problem/1248

#include <stdio.h>

int N;
char S[60];
char s_table[11][11];

bool found = false;
int sum[11];
int ans[11];

void Solve(int nth) {
  if (nth == N + 1) {
    found = true;
    return;
  }

  for (int i = -10; i <= 10; i++) {
    sum[nth] = sum[nth - 1] + i;
    ans[nth] = i;
    bool pass = true;
    for (int j = 1; j <= nth; j++) {
      int s = sum[nth] - sum[j - 1];

      char sign = '0';
      if (s > 0)
        sign = '+';
      else if (s < 0)
        sign = '-';

      if (s_table[j][nth] != sign) {
        pass = false;
        break;
      }
    }
    if (pass) Solve(nth + 1);
    if (found) return;
  }
}

int main() {
  scanf("%d%s", &N, S);
  int k = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j++) {
      s_table[i][j] = S[k++];
    }
  }

  Solve(1);
  for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
