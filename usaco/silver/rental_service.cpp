// Rental Service (Silver)
// https://www.acmicpc.net/problem/15590

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, r;
  cin >> n >> m >> r;
  vector<int> nv(n), rv(r);
  vector<pair<int, int>> mv(m);
  for (int i = 0; i < n; ++i) cin >> nv[i];
  for (int i = 0; i < m; ++i) cin >> mv[i].first >> mv[i].second;
  for (int i = 0; i < r; ++i) cin >> rv[i];

  sort(nv.rbegin(), nv.rend());
  sort(mv.begin(), mv.end(),
       [&](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
  sort(rv.rbegin(), rv.rend());

  vector<ll> psr(max(n + 1, r + 1), 0);
  for (int i = 1; i <= max(r, n); ++i)
    psr[i] = psr[i - 1] + (i - 1 < r ? rv[i - 1] : 0);

  int j = 0;  // index of mv
  ll sum = 0;
  ll ans = psr[0];
  for (int i = 0; i < n; ++i) {
    int c = nv[i];
    while (j < m && c > 0) {
      int amt = min(c, mv[j].first);
      sum += (ll)mv[j].second * amt;
      mv[j].first -= amt;
      c -= amt;
      if (mv[j].first == 0) j++;
    }
    ans = max(ans, sum + psr[n - i - 1]);
  }

  cout << ans << "\n";

  return 0;
}