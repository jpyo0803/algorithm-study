// 중앙값
// https://www.acmicpc.net/problem/1572

#include <stdio.h>

int N, K, x;
int arr[250000];

int segment_tree[65536 * 4];

int Update(int node, int node_left, int node_right, int index, int value) {
  if (index < node_left || node_right < index) return segment_tree[node];
  if (node_left == node_right) {
    return segment_tree[node] += value;
  }

  int mid = (node_left + node_right) / 2;
  return segment_tree[node] =
             Update(node * 2, node_left, mid, index, value) +
             Update(node * 2 + 1, mid + 1, node_right, index, value);
}

int GetMedian(int node, int node_left, int node_right, int k) {
  if (node_left == node_right) return node_left;
  int l = segment_tree[node * 2];
  int mid = (node_left + node_right) / 2;
  if (l < k)
    return GetMedian(node * 2 + 1, mid + 1, node_right, k - l);
  else
    return GetMedian(node * 2, node_left, mid, k);
}

int main() {
  scanf("%d%d", &N, &K);
  int nth = (K + 1) / 2;

  for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);

  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    Update(1, 0, 65536, arr[i], 1);
    if (i >= K - 1) {
      ans += GetMedian(1, 0, 65536, nth);
      Update(1, 0, 65536, arr[i - K + 1], -1);
    }
  }

  printf("%lld\n", ans);

  return 0;
}