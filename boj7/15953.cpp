// 상금 헌터
// https://www.acmicpc.net/problem/15953

#include <stdio.h>

int T, a, b;

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d%d", &a, &b);
    int ans = 0;
    if (0 < a && a <= 1)
      ans += 500;
    else if (1 < a && a <= 3)
      ans += 300;
    else if (3 < a && a <= 6)
      ans += 200;
    else if (6 < a && a <= 10)
      ans += 50;
    else if (10 < a && a <= 15)
      ans += 30;
    else if (15 < a && a <= 21)
      ans += 10;

    if (0 < b && b <= 1)
      ans += 512;
    else if (1 < b && b <= 3)
      ans += 256;
    else if (3 < b && b <= 7)
      ans += 128;
    else if (7 < b && b <= 15)
      ans += 64;
    else if (15 < b && b <= 31)
      ans += 32;

    printf("%d\n", ans * 10000);
  }
  return 0;
}
