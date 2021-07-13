// 수열과 쿼리 17
// https://www.acmicpc.net/problem/14438

#include <stdio.h>

constexpr int kInf = 1000000007;

int N, M, cmd, a, b;

int segment_tree[100000 * 4];

int Min(int x, int y) { return x < y ? x : y; }

int Update(int n, int nl, int nr, int ind, int val) {
  if (nr < ind || ind < nl) return segment_tree[n];
  if (nl == nr) return segment_tree[n] = val;

  int mid = (nl + nr) / 2;
  return segment_tree[n] = Min(Update(n * 2, nl, mid, ind, val),
                               Update(n * 2 + 1, mid + 1, nr, ind, val));
}

int Query(int n, int nl, int nr, int s, int e) {
  if (nr < s || e < nl) return kInf;
  if (s <= nl && nr <= e) return segment_tree[n];

  int mid = (nl + nr) / 2;
  return Min(Query(n * 2, nl, mid, s, e), Query(n * 2 + 1, mid + 1, nr, s, e));
}

int main() {
  scanf("%d", &N);
  for (int n = 1; n <= N; ++n) {
    int x;
    scanf("%d", &x);
    Update(1, 1, N, n, x);
  }

  scanf("%d", &M);
  for (int m = 0; m < M; ++m) {
    scanf("%d%d%d", &cmd, &a, &b);
    if (cmd == 1) {
      Update(1, 1, N, a, b);
    } else {
      printf("%d\n", Query(1, 1, N, a, b));
    }
  }
  return 0;
}