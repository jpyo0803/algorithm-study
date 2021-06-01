// 수열과 쿼리 21
// https://www.acmicpc.net/problem/16975

#include <stdio.h>

int N, M, a, b, c;
long long d;

long long array[100000];
long long segment_tree[400000];
long long lazy[400000];

void Init(int l, int r, int node) {
  if (l == r) {
    segment_tree[node] = array[l];
    return;
  }
  int mid = (l + r) / 2;
  Init(l, mid, node * 2);
  Init(mid + 1, r, node * 2 + 1);
}

void Propagate(int l, int r, int node) {
  if (lazy[node] == 0) return;
  segment_tree[node] += lazy[node];
  if (l < r) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

long long Query(int x, int node, int nl, int nr) {
  Propagate(nl, nr, node);
  if (x < nl || x > nr) return 0;
  if (nl == nr && nl == x) return segment_tree[node];
  int mid = (nl + nr) / 2;
  return Query(x, node * 2, nl, mid) + Query(x, node * 2 + 1, mid + 1, nr);
}

void Update(int l, int r, int node, int nl, int nr, long long value) {
  Propagate(nl, nr, node);
  if (nr < l || nl > r) return;
  if (l <= nl && nr <= r) {
    lazy[node] += value;
    return;
  }
  int mid = (nl + nr) / 2;
  Update(l, r, node * 2, nl, mid, value);
  Update(l, r, node * 2 + 1, mid + 1, nr, value);
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%lld", &array[i]);
  Init(0, N - 1, 1);

  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d%d%lld", &b, &c, &d);
      Update(b - 1, c - 1, 1, 0, N - 1, d);
    } else {
      scanf("%d", &b);
      printf("%lld\n", Query(b - 1, 1, 0, N - 1));
    }
  }
  return 0;
}
