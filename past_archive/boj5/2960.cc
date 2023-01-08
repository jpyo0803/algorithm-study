//
// 에라토스테네스의 체
// Link: https://www.acmicpc.net/problem/2960
//

#include <cstdio>

int N, K;
bool numbers[1001];

int main() {
  int base = 2;
  int nth = 0;
  scanf("%d%d", &N, &K);
  while (true) {
    if (!numbers[base]) {
      int next = base;
      while (next <= N) {
        if (!numbers[next]) {
          numbers[next] = true;
          if (++nth == K) {
            printf("%d\n", next);
            return 0;
          }
        }
        next += base;
      }
    }
    base++;
  }
  return 0;
}