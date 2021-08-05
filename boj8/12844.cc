// XOR
// https://www.acmicpc.net/problem/12844

#include <stdio.h>

int N, M, c, i, j, k;

int segment_tree[500000 * 4];
int lazy[500000 * 4];
int arr[500000];

void Swap(int& x, int& y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int Init(int node, int node_left, int node_right) {
  if (node_left == node_right) return segment_tree[node] = arr[node_left];

  int mid = (node_left + node_right) / 2;
  return segment_tree[node] = Init(node * 2, node_left, mid) ^
                              Init(node * 2 + 1, mid + 1, node_right);
}

void Propagate(int node, int node_left, int node_right) {
  if (lazy[node] != 0) {
    if (node_left != node_right) {
      lazy[node * 2] ^= lazy[node];
      lazy[node * 2 + 1] ^= lazy[node];
    }
    segment_tree[node] ^= lazy[node] * ((node_right - node_left + 1) % 2);
    lazy[node] = 0;
  }
}

int UpdateRange(int node, int node_left, int node_right, int start, int end,
                int k) {
  Propagate(node, node_left, node_right);
  if (node_right < start || end < node_left) return segment_tree[node];
  if (start <= node_left && node_right <= end) {
    segment_tree[node] ^= k * ((node_right - node_left + 1) % 2);
    if (node_left != node_right) {
      lazy[node * 2] ^= k;
      lazy[node * 2 + 1] ^= k;
    }
    return segment_tree[node];
  }

  int mid = (node_left + node_right) / 2;
  return segment_tree[node] =
             UpdateRange(node * 2, node_left, mid, start, end, k) ^
             UpdateRange(node * 2 + 1, mid + 1, node_right, start, end, k);
}

int Query(int node, int node_left, int node_right, int start, int end) {
  Propagate(node, node_left, node_right);
  if (end < node_left || node_right < start) return 0;
  if (start <= node_left && node_right <= end) return segment_tree[node];

  int mid = (node_left + node_right) / 2;
  return Query(node * 2, node_left, mid, start, end) ^
         Query(node * 2 + 1, mid + 1, node_right, start, end);
}

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; n++) scanf("%d", &arr[n]);

  Init(1, 0, N - 1);

  scanf("%d", &M);
  for (int m = 0; m < M; m++) {
    scanf("%d%d%d", &c, &i, &j);
    if (i > j) Swap(i, j);
    if (c == 1) {
      scanf("%d", &k);
      UpdateRange(1, 0, N - 1, i, j, k);
    } else {  // c == , 출력
      printf("%d\n", Query(1, 0, N - 1, i, j));
    }
  }
  return 0;
}