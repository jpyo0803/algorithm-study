// Factory Machines
// https://cses.fi/problemset/task/1620

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, t;
  cin >> n >> t;
  vector<int> kv(n);
  for (auto& e : kv) cin >> e;

  ll lo = 0, hi = 1e18;
  while (lo <= hi) {
    ll m = (lo + hi) / 2;

    ll cnt = 0;
    for (auto e : kv) {
      cnt += m / e;
      if (cnt >= t) break;
    }
    if (cnt >= t) {
      hi = m - 1;
    } else {
      lo = m + 1;
    }
  }
  cout << lo << "\n";

  return 0;
}