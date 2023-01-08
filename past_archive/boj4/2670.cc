//
// 연속부분 최대곱
// Link: https://www.acmicpc.net/problem/2670
//

#include <cstdio>

int N;
double x;
double A[10000];
double cache[10000];

double Max(double x, double y) { return x > y ? x : y; }

double Solve() {
  double ans;
  ans = cache[0] = A[0];
  for (int i = 1; i < N; i++) {
    cache[i] = Max(A[i], cache[i - 1] * A[i]);
    ans = Max(ans, cache[i]);
  }
  return ans;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%lf", &A[i]);
  printf("%0.3lf\n", Solve());

  return 0;
}