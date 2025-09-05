// A - Not Acceptable (ABC)
// https://atcoder.jp/contests/abc406/tasks/abc406_a

#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> a >> b >> c >> d;

  bool ok = true;
  if (a == c) {
    ok = b > d;
  } else {
    ok = a > c;
  }

  cout << (ok ? "Yes" : "No") << "\n";

  return 0;
}