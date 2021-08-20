// Four Squares
// https://www.acmicpc.net/problem/17626

#include <stdio.h>

int N;
int ans = 987654321;

void Solve(int rem, int nth) {
  if (ans <= nth) return;
  if (nth == 5) return;

  for (int i = 1; i * i <= rem; ++i) {
    if (rem - i * i == 0) {
      ans = nth < ans ? nth : ans;
    } else {
      Solve(rem - i * i, nth + 1);
    }
  }
}

int main() {
  scanf("%d", &N);
  Solve(N, 1);

  printf("%d\n", ans);
  return 0;
}