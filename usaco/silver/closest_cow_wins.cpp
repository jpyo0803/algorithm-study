// Closest Cow Wins (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=1158

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int k, m, n;
  cin >> k >> m >> n;
  vector<pair<int, int>> vv(k);
  for (auto& e : vv) cin >> e.first >> e.second;
  vector<int> nv(m);
  for (auto& e : nv) cin >> e;

  sort(vv.begin(), vv.end());
  sort(nv.begin(), nv.end());

  vector<ll> cand; // tastiness cand
  int j = 0;
  for (int i = 0; i + 1 < m; ++i) {
    int A = nv[i], B = nv[i + 1];
    vector<pair<int, int>> seg;
    ll tot = 0;
    while (j < k && vv[j].first < B) {
      tot += vv[j].second;
      seg.push_back(vv[j++]);
    }

    int prev = 0;
    ll ma = 0;
    ll rs = 0;
    for (auto [p2, t] : seg) {
      int p1 = seg[prev].first;
      rs += t;
      if (2 * (p2 - p1) >= B - A) {
        rs -= seg[prev].second;
        prev++;
      }
      ma = max(ma, rs);
    }
    cand.push_back(ma);
    cand.push_back(tot - ma);
  }

  ll sum = 0;
  ll sum2 = 0;
  for (auto [x, y] : vv) {
    if (x < nv[0]) sum += y;
    if (x > nv.back()) sum2 += y;
  }
  cand.push_back(sum);
  cand.push_back(sum2);

  sort(cand.begin(), cand.end());

  ll ans = 0;
  while (n-- && cand.size()) {
    ans += cand.back();
    cand.pop_back();
  }
  
  cout << ans << "\n";

  return 0;
}