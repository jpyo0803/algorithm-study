//
// 진수변환기
// Link: https://www.acmicpc.net/problem/14915
//

#include <stdio.h>

int m, n;

void BaseConverter(int quotient, int base) {
  if (quotient == 0) return;
  BaseConverter(quotient / base, base);
  char digit;
  int rem = quotient % base;
  if (rem >= 10)
    digit = 'A' + (rem - 10);
  else
    digit = '0' + rem;
  printf("%c", digit);
}

int main() {
  scanf("%d%d", &m, &n);
  if (m == 0) {
    printf("0\n");
    return 0;
  }
  BaseConverter(m, n);
  printf("\n");
  return 0;
}
