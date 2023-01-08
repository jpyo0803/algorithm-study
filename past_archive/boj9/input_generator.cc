#include <stdio.h>

#include <cstdlib>
#include <ctime>

int N;

int main() {
  N = 10000;
  srand(time(NULL));
  printf("%d\n", N);
  for (int i = 0; i < N; ++i) {
    // printf("%d\n", rand() % 1000001a);
    printf("%d\n", 500000 - i);
  }
  return 0;
}