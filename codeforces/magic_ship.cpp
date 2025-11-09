// Magic Ship
// https://codeforces.com/problemset/problem/1117/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int x1, y1, x2, y2, n;
  string s;

  cin >> x1 >> y1 >> x2 >> y2;

  cin >> n >> s;

  ll x_cycle = 0, y_cycle = 0;
  for (auto ch : s) {
    if (ch == 'U') y_cycle++;
    else if (ch == 'D') y_cycle--;
    else if (ch == 'R') x_cycle++;
    else x_cycle--;
  }

  ll ans = -1;
  ll lo = 1, hi = 1e15;
  while (lo < hi) {
    ll m = lo + (hi - 1 - lo) / 2;

    bool ok = false;

    ll q = m / n;
    ll rem = m % n;

    ll curr_x = q * x_cycle + x1;
    ll curr_y = q * y_cycle + y1;

    for (int i = 0; i < rem; ++i) {
      if (s[i] == 'U') curr_y++;
      else if (s[i] == 'D') curr_y--;
      else if (s[i] == 'R') curr_x++;
      else curr_x--;
    }

    if (abs(curr_x - x2) + abs(curr_y - y2) <= m) {
      ans = m;
      hi = m;
    } else {
      lo = m + 1;
    }
  }

  cout << ans << "\n";

  return 0;
}