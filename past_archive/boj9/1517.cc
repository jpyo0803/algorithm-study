// 버블소트
// https://www.acmicpc.net/problem/1517

#include <stdint.h>
#include <stdio.h>

#include <algorithm>
#include <map>

using namespace std;

int N;
int arr[500'010];
int sorted_arr[500'010];
int segment_tree[2'000'010];

map<int, int> mapped_arr;

int Update(int n, int nl, int nr, int x, int v) {
  if (x < nl || nr < x) return segment_tree[n];
  if (nl == nr) return segment_tree[n] = v;

  int mid = (nl + nr) / 2;
  return segment_tree[n] = Update(n * 2, nl, mid, x, v) +
                           Update(n * 2 + 1, mid + 1, nr, x, v);
}

int Query(int n, int nl, int nr, int s, int e) {
  if (e < nl || nr < s) return 0;
  if (s <= nl && nr <= e) return segment_tree[n];

  int mid = (nl + nr) / 2;
  return Query(n * 2, nl, mid, s, e) + Query(n * 2 + 1, mid + 1, nr, s, e);
}

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; ++n) {
    int x;
    scanf("%d", &x);
    arr[n] = sorted_arr[n] = x;
  }
  sort(sorted_arr, sorted_arr + N);

  for (int n = 0; n < N; ++n) {
    mapped_arr[sorted_arr[n]] = n;
  }

  int64_t ans = 0;
  for (int n = 0; n < N; ++n) {
    int v = mapped_arr[arr[n]];
    ans += Query(1, 0, N - 1, v + 1, N - 1);
    Update(1, 0, N - 1, v, 1);
  }

  printf("%lld\n", ans);

  return 0;
}