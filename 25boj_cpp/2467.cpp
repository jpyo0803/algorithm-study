// 용액
// https://www.acmicpc.net/problem/2467

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i];

  int ans = 2e9 + 10; // abs compare
  int ans_l, ans_r;

  int l = 0;
  int r = n - 1;

  while (l < r) {
    int cand = vv[l] + vv[r];
    if (abs(cand) < ans) {
      ans = abs(cand);
      ans_l = vv[l];
      ans_r = vv[r];
    }

    if (cand < 0) {
      l++;
    } else {
      r--;
    }
  }

  cout << ans_l << " " << ans_r << "\n";

  return 0;
}