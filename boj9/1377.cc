// 버블소트
// https://www.acmicpc.net/problem/1377

#include <stdio.h>

int N;
int segment_tree[1'000'000 * 4];

int Max(int x, int y) { return x < y ? y : x; }

int Update(int n, int nl, int nr, int x) {
  if (x < nl || nr < x) return segment_tree[n];
  if (nl == nr) return ++segment_tree[n];

  int mid = (nl + nr) / 2;
  return segment_tree[n] =
             Update(n * 2, nl, mid, x) + Update(n * 2 + 1, mid + 1, nr, x);
}

int Query(int n, int nl, int nr, int s, int e) {
  if (e < nl || nr < s) return 0;
  if (s <= nl && nr <= e) return segment_tree[n];

  int mid = (nl + nr) / 2;
  return Query(n * 2, nl, mid, s, e) + Query(n * 2 + 1, mid + 1, nr, s, e);
}

int main() {
  scanf("%d", &N);

  int max_seq = 0;
  for (int n = 1; n <= N; ++n) {
    int x;
    scanf("%d", &x);
    max_seq = Max(max_seq, Query(1, 0, 1'000'000, x + 1, 1'000'000) + 1);
    Update(1, 0, 1'000'000, x);
  }

  printf("%d\n", max_seq);

  return 0;
}