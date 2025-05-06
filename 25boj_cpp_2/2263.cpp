// 트리의 순회
// https://www.acmicpc.net/problem/2263

#include <bits/stdc++.h>

using namespace std;

int n;
int inorder[100005];
int postorder[100005];
int pos[100005];

void Solve(int in_l, int in_r, int post_l, int post_r) {
  if (in_l > in_r) return;
  int pivot = postorder[post_r];
  cout << pivot << " ";

  int pivot_pos = pos[pivot];
  int left_len = pivot_pos - in_l;
  Solve(in_l, in_l + left_len - 1, post_l, post_l + left_len - 1); // left
  Solve(pivot_pos + 1, in_r, post_l + left_len, post_r - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> inorder[i];
    pos[inorder[i]] = i;
  }
  for (int i = 0; i < n; ++i) cin >> postorder[i];

  Solve(0, n - 1, 0, n - 1);

  return 0;
}