// A - G1 (ABC)
// https://atcoder.jp/contests/abc410/tasks/abc410_a

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  cin >> k;
  int ans = 0;
  for (auto e : arr) {
    if (k <= e) ans++;
  }
  cout << ans << "\n";

  return 0;
}