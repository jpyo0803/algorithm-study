// A - Task Failed Successfully (ABC)
// https://atcoder.jp/contests/abc412/tasks/abc412_a

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a < b) ans++;
  }
  cout << ans << "\n";

  return 0;
}