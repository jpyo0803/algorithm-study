// A - Approximation (ABC)
// https://atcoder.jp/contests/abc407/tasks/abc407_a

#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> a >> b;

  cout << (a + b / 2) / b << "\n";

  return 0;
}