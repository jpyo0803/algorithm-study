// 삼각형 만들기
// https://www.acmicpc.net/source/29475440

#include <math.h>
#include <stdio.h>

int N;

int Solve(int n) {
  int ans = 0;
  for (int a = ceil((double)n / 3); a <= ((double)n - 1) / 2; a++) {
    int x = (n - a);
    ans += x / 2 - x + a + 1;
  }
  return ans;
}

int main() {
  scanf("%d", &N);
  printf("%d\n", Solve(N));
  return 0;
}
