// 공장
// https://www.acmicpc.net/problem/7578

#include <stdio.h>

long long segment_tree[2000000];

int N, x;

int index_map[1000001];
int index_arr[500001];

long long Query(int node, int node_left, int node_right, int left, int right) {
  if (node_left > right || node_right < left) return 0;
  if (left <= node_left && node_right <= right) return segment_tree[node];

  int mid = (node_left + node_right) / 2;
  return Query(node * 2, node_left, mid, left, right) +
         Query(node * 2 + 1, mid + 1, node_right, left, right);
}

long long Update(int node, int node_left, int node_right, int index) {
  if (node_left > index || node_right < index) return segment_tree[node];
  if (node_left == node_right) return segment_tree[node] = 1;

  int mid = (node_left + node_right) / 2;
  return segment_tree[node] = Update(node * 2, node_left, mid, index) +
                              Update(node * 2 + 1, mid + 1, node_right, index);
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &x);
    index_map[x] = i;
  }

  for (int i = 1; i <= N; i++) {
    scanf("%d", &x);
    index_arr[i] = index_map[x];
  }

  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += Query(1, 1, N, index_arr[i] + 1, N);
    Update(1, 1, N, index_arr[i]);
  }

  printf("%lld\n", ans);

  return 0;
}
