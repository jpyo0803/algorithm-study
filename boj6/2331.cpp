// 반복수열
// https://www.acmicpc.net/problem/2331

#include <stdio.h>

int A, P;
int visit_count[250000];

int Pow(int base, int exp) {
  if (exp == 0) return 1;
  if (exp == 1) return base;

  int res = Pow(base, exp / 2);
  res *= res;

  if (exp % 2) res *= base;
  return res;
}

int DigitPowSum(int x, int p) {
  int sum = 0;
  while (x > 0) {
    int digit = x % 10;
    x /= 10;
    sum += Pow(digit, p);
  }
  return sum;
}

int Dfs(int a, int p) {
  if (++visit_count[a] == 3) return 0;
  int ret = Dfs(DigitPowSum(a, p), p);
  if (visit_count[a] == 1) ret += 1;
  return ret;
}

int main() {
  scanf("%d%d", &A, &P);
  printf("%d\n", Dfs(A, P));

  return 0;
}
