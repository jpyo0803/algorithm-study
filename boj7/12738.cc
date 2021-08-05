// 가장 긴 증가하는 부분 수열 3
// https://www.acmicpc.net/problem/12738

#include <stdio.h>

int N, x;
int arr[1000001];

int Max(int x, int y) { return x < y ? y : x; }

int LowerBound(int s, int e, int x) {
  while (e - s > 0) {
    int m = (e + s) / 2;
    if (arr[m] < x)
      s = m + 1;
    else
      e = m;
  }
  return s;
}

int Solve(int n) {
  int len = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    int index = LowerBound(0, len, x);
    arr[index] = x;
    if (len == index) len++;
  }
  return len;
}

int main() {
  scanf("%d", &N);
  printf("%d\n", Solve(N));
  return 0;
}
