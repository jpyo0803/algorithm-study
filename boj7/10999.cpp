// 구간 합 구하기2
// https://www.acmicpc.net/problem/10999

#include <stdio.h>

int N, M, K, a, b, c;
long long d;

long long array[1000000];
long long segment_tree[4000000];
long long lazy[4000000];

void Propagate(int left, int right, int node) {
  if (lazy[node] == 0) return;
  segment_tree[node] += (right - left + 1) * lazy[node];
  if (left < right) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

long long Init(int left, int right, int node) {
  if (left == right) return segment_tree[node] = array[left];
  int mid = (left + right) / 2;
  long long left_sum = Init(left, mid, node * 2);
  long long right_sum = Init(mid + 1, right, node * 2 + 1);
  return segment_tree[node] = left_sum + right_sum;
}

long long Query(int left, int right, int node, int node_left, int node_right) {
  Propagate(node_left, node_right, node);
  if (right < node_left || left > node_right) return 0;
  if (left <= node_left && node_right <= right) return segment_tree[node];

  int mid = (node_left + node_right) / 2;
  long long left_sum = Query(left, right, node * 2, node_left, mid);
  long long right_sum = Query(left, right, node * 2 + 1, mid + 1, node_right);
  return left_sum + right_sum;
}

void Update(int left, int right, int node, int node_left, int node_right,
            long long value) {
  Propagate(node_left, node_right, node);
  if (right < node_left || left > node_right) return;
  if (left <= node_left && node_right <= right) {
    segment_tree[node] += (node_right - node_left + 1) * value;
    if (node_left < node_right) {
      lazy[node * 2] += value;
      lazy[node * 2 + 1] += value;
    }
    return;
  }
  int mid = (node_left + node_right) / 2;
  Update(left, right, node * 2, node_left, mid, value);
  Update(left, right, node * 2 + 1, mid + 1, node_right, value);
  segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}

int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < N; i++) scanf("%lld", &array[i]);
  Init(0, N - 1, 1);

  for (int i = 0; i < M + K; i++) {
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d%d%lld", &b, &c, &d);
      Update(b - 1, c - 1, 1, 0, N - 1, d);
    } else {
      scanf("%d%d", &b, &c);
      printf("%lld\n", Query(b - 1, c - 1, 1, 0, N - 1));
    }
  }
  return 0;
}
