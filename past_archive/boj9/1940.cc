// 주몽
// https://www.acmicpc.net/problem/1940

#include <stdio.h>

#include <algorithm>

using namespace std;

int N, M;
int arr[15'010];

int Solve() {
  sort(arr, arr + N);
  int l = 0, h = N - 1;

  int ans = 0;
  while (l < h) {
    int sum = arr[l] + arr[h];
    if (sum == M) {
      ++ans;
      ++l;
    } else if (sum < M) {
      ++l;
    } else {
      --h;
    }
  }
  return ans;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int n = 0; n < N; ++n) scanf("%d", &arr[n]);
  printf("%d\n", Solve());

  return 0;
}