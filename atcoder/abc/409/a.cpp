// A - Conflict (ABC)
// https://atcoder.jp/contests/abc409/tasks/abc409_a

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  string t, a;
  cin >> t >> a;

  bool ok = false;
  for (int i = 0; i < n; ++i) {
    if (t[i] == 'o' && a[i] == 'o') ok = true;
  }
  cout << (ok ? "Yes" : "No") << "\n";

  return 0;
}