// Digit Queries
// https://cses.fi/problemset/task/2431/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int q;

int Solve(ll k) {
  ll i = 1, f = 9, s = 0;
  while (true) {
    if (k - i * f <= 0) break;
    k -= i * f;
    s += f;
    i++, f *= 10;
  }
  // cout << k << " : " << i << " / " << f << " / " << s << endl;
  s += k / i;
  if (k % i) s++;
  auto str = to_string(s);
  return str[(k + i - 1) % i] - '0';

  // i = 자리수,
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> q;
  while (q--) {
    ll k;
    cin >> k;
    cout << Solve(k) << "\n";
  }

  return 0;
}