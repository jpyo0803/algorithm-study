// 수열과 쿼리 15
// https://www.acmicpc.net/problem/14427

#include <stdio.h>

int N, M, cmd, a, b;

int min_tree[100000 * 4];
int ind_tree[100000 * 4];

int Min(int x, int y) { return x < y ? x : y; }

void Update(int n, int nl, int nr, int ind, int val) {
  if (nr < ind || ind < nl) return;
  if (nl == nr) {
    min_tree[n] = val;
    ind_tree[n] = ind;
    return;
  }

  int mid = (nl + nr) / 2;
  Update(n * 2, nl, mid, ind, val);
  Update(n * 2 + 1, mid + 1, nr, ind, val);
  min_tree[n] = Min(min_tree[n * 2], min_tree[n * 2 + 1]);
  if (min_tree[n] == min_tree[n * 2])
    ind_tree[n] = ind_tree[n * 2];
  else
    ind_tree[n] = ind_tree[n * 2 + 1];
  if (min_tree[n * 2] == min_tree[n * 2 + 1]) {
    ind_tree[n] = Min(ind_tree[n * 2], ind_tree[n * 2 + 1]);
  }
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
    scanf("%d", &cmd);
    if (cmd == 1) {  // Update
      scanf("%d%d", &a, &b);
      Update(1, 1, N, a, b);
    } else {  // Query
      printf("%d\n", ind_tree[1]);
    }
  }

  return 0;
}