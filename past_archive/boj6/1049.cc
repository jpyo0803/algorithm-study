// 기타줄
// https://www.acmicpc.net/problem/1049

#include <stdio.h>

int N, M, min_bundle = 10000, min_each = 10000;

int Min(int x, int y) { return x < y ? x : y; }

int Solve() {
  int quotient = N / 6;
  int remainder = N % 6;
  int ret = Min(quotient * min_bundle, quotient * 6 * min_each);
  if (remainder > 0) {
    ret = Min(ret + min_bundle, ret + (remainder * min_each));
  }
  return ret;
}

int main() {
  scanf("%d%d", &N, &M);

  int bundle, each;
  for (int m = 0; m < M; m++) {
    scanf("%d%d", &bundle, &each);
    min_bundle = Min(min_bundle, bundle);
    min_each = Min(min_each, each);
  }

  printf("%d\n", Solve());
  return 0;
}
