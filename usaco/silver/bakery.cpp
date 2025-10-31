// Bakery (Silver)
// https://www.acmicpc.net/problem/27846

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
ll t_c, t_m;

tuple<ll, ll, ll> rv[105];

bool F(ll w) {
  ll ub = min(t_c, t_c - w + t_m - 1);
  ll lb = max(1LL, t_c - w);
  for (int i = 0; i < n; ++i) {
    ll a, b, c;
    tie(a, b, c) = rv[i];
    ll d = t_c + t_m - w;
    if (a > b) {
      ub = min(ub, (c - b * d) / (a - b));
    } else if (a < b) {
      lb = max(lb, (b * d - c + (b - a - 1)) / (b - a));
    } else {
      if (b * d > c) return false;
    }
  }
  return ub >= lb;
}

ll Solve(ll lo, ll hi) {
  // find min w that satisfy
  hi++;
  while (lo < hi) {
    ll w = lo + (hi - 1 - lo) / 2;
    if (F(w)) {
      hi = w;
    } else {
      lo = w + 1;
    }
  }
  return hi;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> t_c >> t_m;
    for (int i = 0; i < n; ++i) {
      cin >> get<0>(rv[i]) >> get<1>(rv[i]) >> get<2>(rv[i]);
    }

    cout << Solve(0, t_c + t_m - 2) << "\n";
  }

  return 0;
}