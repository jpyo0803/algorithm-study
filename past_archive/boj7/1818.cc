// 책정리
// https://www.acmicpc.net/problem/1818

#include <stdio.h>

int N, x;
int arr[200010];

int LowerBound(int s, int e, int x) {
  while (e - s > 0) {
    int m = (s + e) / 2;
    if (arr[m] < x)
      s = m + 1;
    else
      e = m;
  }
  return s;
}

int Solve(const int n) {
  int len = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    int index = LowerBound(0, len, x);
    arr[index] = x;
    if (len == index) len++;
  }

  return N - len;
}

int main() {
  scanf("%d", &N);
  printf("%d\n", Solve(N));
  return 0;
}
