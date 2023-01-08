// 스위치
// https://www.acmicpc.net/problem/1395

#include <stdio.h>

int N, M, O, S, T;

int array[100000];
int segment_tree[400000];
int lazy[400000];

void Propagate(int l, int r, int node) {
  if (lazy[node] == 0) return;
  int rem = lazy[node] % 2;
  if (rem) segment_tree[node] = r - l + 1 - segment_tree[node];
  if (l < r) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

void Update(int l, int r, int node, int nl, int nr) {
  Propagate(nl, nr, node);
  if (nl > r || nr < l) return;
  if (l <= nl && nr <= r) {
    segment_tree[node] = nr - nl + 1 - segment_tree[node];
    if (nl < nr) {
      lazy[node * 2] += 1;
      lazy[node * 2 + 1] += 1;
    }
    return;
  }
  int mid = (nl + nr) / 2;
  Update(l, r, node * 2, nl, mid);
  Update(l, r, node * 2 + 1, mid + 1, nr);
  segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}

int Query(int l, int r, int node, int nl, int nr) {
  Propagate(nl, nr, node);
  if (nl > r || nr < l) return 0;
  if (l <= nl && nr <= r) return segment_tree[node];
  int mid = (nl + nr) / 2;
  int left_ret = Query(l, r, node * 2, nl, mid);
  int right_ret = Query(l, r, node * 2 + 1, mid + 1, nr);
  return left_ret + right_ret;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", &O, &S, &T);
    if (O == 0) {
      Update(S - 1, T - 1, 1, 0, N - 1);
    } else {
      printf("%d\n", Query(S - 1, T - 1, 1, 0, N - 1));
    }
  }
  return 0;
}
