// 사탕상자
// https://www.acmicpc.net/problem/2243

#include <stdio.h>

int N, A, B, C;

int segment_tree[1000001 * 4];

int Update(int n, int nl, int nr, int ind, int val) {
  if (ind < nl || nr < ind) return segment_tree[n];
  if (nl == nr) return segment_tree[n] += val;

  int mid = (nl + nr) / 2;
  return segment_tree[n] = Update(n * 2, nl, mid, ind, val) +
                           Update(n * 2 + 1, mid + 1, nr, ind, val);
}

int Query(int n, int nl, int nr, int rem) {
  if (nl == nr) return nl;
  int left = segment_tree[n * 2];
  int mid = (nl + nr) / 2;
  if (rem <= left) return Query(n * 2, nl, mid, rem);
  return Query(n * 2 + 1, mid + 1, nr, rem - left);
}

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; ++n) {
    scanf("%d", &A);
    if (A == 1) {
      scanf("%d", &B);
      int which = Query(1, 1, 1000000, B);
      Update(1, 1, 1000000, which, -1);
      printf("%d\n", which);
    } else {
      scanf("%d%d", &B, &C);
      Update(1, 1, 1000000, B, C);
    }
  }
  return 0;
}