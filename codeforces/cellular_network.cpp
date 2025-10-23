// Cellular Network
// https://codeforces.com/contest/702/problem/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int UpperBound(const vector<int>& v, int n, ll x) {
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (v[mid] <= x) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> av(n), bv(m);
  for (auto& e : av) cin >> e;
  for (auto& e : bv) cin >> e;
  sort(bv.begin(), bv.end());

  int ans = 0;
  for (auto e : av) {
    int pos = UpperBound(bv, m, e);
    int ldist = 2e9;
    int rdist = 2e9;
    if (pos != m) rdist = bv[pos] - e;
    if (pos != 0) ldist = e - bv[pos - 1];
    ans = max(ans, min(ldist, rdist));
  }
  cout << ans << "\n";

  return 0;
}