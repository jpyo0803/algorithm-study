// 방 배정
// https://www.acmicpc.net/problem/13300

#include <stdio.h>

int N, K;
int students[7][2];  // ie) 0, 0 = number of female students in 1st grade

int main() {
  scanf("%d%d", &N, &K);
  for (int n = 0; n < N; ++n) {
    int s, g;
    scanf("%d%d", &s, &g);
    ++students[g][s];
  }

  int k = 0;
  for (int g = 1; g <= 6; ++g) {
    for (int s = 0; s < 2; ++s) {
      k += students[g][s] / K;
      if (students[g][s] % K > 0) ++k;
    }
  }
  printf("%d\n", k);
  return 0;
}