// 음주 코딩
// https://www.acmicpc.net/problem/5676

#include <stdio.h>

int N, K, a, b;
char c;

int arr[100001];
int segment_tree[400001];

int Init(int node, int left, int right) {
  if (left == right) {
    if (arr[left] > 0) return segment_tree[node] = 1;
    if (arr[left] < 0) return segment_tree[node] = -1;
    return segment_tree[node] = 0;
  }

  int mid = (left + right) / 2;
  return segment_tree[node] =
             Init(node * 2, left, mid) * Init(node * 2 + 1, mid + 1, right);
}

int Update(int node, int left, int right, int target, int value) {
  if (target < left || right < target)
    return segment_tree[node];
  else if (left == right && left == target) {
    if (value > 0) return segment_tree[node] = 1;
    if (value < 0) return segment_tree[node] = -1;
    return segment_tree[node] = 0;
  }

  int mid = (left + right) / 2;
  return segment_tree[node] =
             Update(node * 2, left, mid, target, value) *
             Update(node * 2 + 1, mid + 1, right, target, value);
}

int Query(int node, int node_left, int node_right, int left, int right) {
  if (right < node_left || node_right < left)
    return 1;
  else if (node_left <= left && right <= node_right)
    return segment_tree[node];

  int mid = (left + right) / 2;
  return Query(node * 2, node_left, node_right, left, mid) *
         Query(node * 2 + 1, node_left, node_right, mid + 1, right);
}

int main() {
  while (scanf("%d%d", &N, &K) != EOF) {
    for (int n = 0; n < N; n++) scanf("%d", &arr[n]);
    Init(1, 0, N - 1);

    for (int k = 0; k < K; k++) {
      scanf(" %c%d%d", &c, &a, &b);
      if (c == 'C') {
        Update(1, 0, N - 1, a - 1, b);
      } else {
        int ret = Query(1, a - 1, b - 1, 0, N - 1);
        if (ret > 0)
          printf("+");
        else if (ret < 0)
          printf("-");
        else
          printf("0");
      }
    }
    printf("\n");
  }
  return 0;
}
