// A - Required Length (ABC)
// https://atcoder.jp/contests/abc411/tasks/abc411_a

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string p;
  int L;
  cin >> p >> L;
  if (p.length() >= L) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}