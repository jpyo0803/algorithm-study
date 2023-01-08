// 소음
// https://www.acmicpc.net/problem/2935

#include <stdio.h>
#include <string.h>

char A[105];
char B[105];
char op;

void Solve() {
  int length_a = strlen(A);
  int length_b = strlen(B);

  if (op == '*') {
    printf("1");
    for (int i = 0; i < length_a + length_b - 2; ++i) {
      printf("0");
    }
  } else {
    int bigger = length_a > length_b ? length_a : length_b;
    int smaller = length_a + length_b - bigger;

    if (bigger == smaller) {
      printf("2");
      for (int i = 0; i < bigger - 1; ++i) {
        printf("0");
      }
    } else {
      printf("1");
      for (int i = 0; i < bigger - 1; ++i) {
        if (bigger - i - 1 == smaller) {
          printf("1");
        } else {
          printf("0");
        }
      }
    }
  }
  printf("\n");
}

int main() {
  scanf("%s%s%s", A, &op, B);
  Solve();
  return 0;
}