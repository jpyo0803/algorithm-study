// Social Distancing (Silver)
// https://www.acmicpc.net/problem/18877

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
vector<pair<ll, ll>> gv;

bool F(ll d) {
  int i = 0; // cow placement count
  int j = 0; // current range
  ll next = gv[0].first; // last position
  while (i < n && j < m) {
    i++;
    next += d;
    while (j < m && next > gv[j].second) j++;
    if (j == m) break;
    next = max(gv[j].first, next);
  }
  return i == n;
}

ll Solve(ll lo, ll hi) {
  lo--;
  while (lo < hi) {
    ll m = lo + 1 + (hi - (lo + 1)) / 2;
    if (F(m)) {
      lo = m;
    } else {
      hi = m - 1;
    }
  }
  return lo;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    ll a, b;
    cin >> a >> b;
    gv.emplace_back(a, b);
  }
  sort(gv.begin(), gv.end());

  cout << Solve(1, 1e18) << "\n";

  return 0;
}