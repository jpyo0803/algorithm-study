// 수 정렬하기 2
// https://www.acmicpc.net/problem/2751

#include <bits/stdc++.h>

using namespace std;

int n;

int tmp_arr[1000010];

void Solve(vector<int>& arr, int l, int r) {
  if (l == r) return;

  int m = (l + r) / 2;
  Solve(arr, l, m);
  Solve(arr, m + 1, r);

  int lp, rp, p;
  lp = p = l;
  rp = m + 1;

  while (lp <= m && rp <= r) {
    if (arr[lp] < arr[rp]) {
      tmp_arr[p++] = arr[lp++];
    } else {
      tmp_arr[p++] = arr[rp++];
    }
  }

  while (lp <= m) tmp_arr[p++] = arr[lp++];
  while (rp <= r) tmp_arr[p++] = arr[rp++];

  for (int i = l; i <= r; ++i) {
    arr[i] = tmp_arr[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];

  Solve(arr, 0, n - 1);

  for (auto e : arr) {
    cout << e << "\n";
  }

  return 0;
}