// A - Timeout (ABC)
// https://atcoder.jp/contests/abc408/tasks/abc408_a

#include <bits/stdc++.h>

using namespace std;

int n, s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> s;
  int last = 0;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    if (t - last > s) {
      ok = false;
      break;
    }
    last = t;
  }
  cout << (ok ? "Yes" : "No") << "\n";

  return 0;
}