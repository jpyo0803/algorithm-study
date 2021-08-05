#include <stdio.h>

int N;

int main() {
  N = 100000;
  printf("%d\n", N);
  for (int i = 99999; i >= 0; i--) {
    printf("%d %d %d %d\n", i, i, i + 1, i + 1);
  }
  return 0;
}