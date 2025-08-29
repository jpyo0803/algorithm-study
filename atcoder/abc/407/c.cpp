// C - Security 2 (ABC)
// https://atcoder.jp/contests/abc407/tasks/abc407_c

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size();

  int ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    int x = s[i] - '0';
    ans = (x - (ans % 10) + 10) % 10 + ans;
  }
  cout << ans + n << "\n";

  return 0;
}