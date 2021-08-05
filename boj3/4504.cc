//
// Finding Multiples
// Problem: https://www.acmicpc.net/problem/4504
//

#include <cstdio>

int n, e;

int main() {
  scanf("%d", &n);

  scanf("%d", &e);
  while (e != 0) {
    if (e % n == 0) {
      printf("%d is a multiple of %d.\n", e, n);
    } else {
      printf("%d is NOT a multiple of %d.\n", e, n);
    }
    scanf("%d", &e);
  }
  return 0;
}

