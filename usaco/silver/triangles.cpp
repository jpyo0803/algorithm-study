// Triangles (Silver)
// https://www.acmicpc.net/problem/18784

#include <bits/stdc++.h>

#define ll long long

using namespace std;

constexpr ll kMod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
    v[i].first += 10000;
    v[i].second += 10000;
  }

  vector<vector<ll>> xv(20005);
  for (auto [x, y] : v) xv[x].push_back(y);

  vector<vector<ll>> yv(20005);
  for (auto [x, y] : v) yv[y].push_back(x);

  vector<vector<ll>> lps(20005), rps(20005);
  vector<map<int, int>> ref(20005);
  
  for (int y = 0; y <= 20000; ++y) {
    auto& e = yv[y];
    if (e.empty()) continue;
    sort(e.begin(), e.end());
    // cout << "y : " << y << " / " << "Sz : " << e.size() << endl;

    int sz = e.size();
    lps[y] = vector<ll>(sz);
    rps[y] = vector<ll>(sz);

    for (int j = 0; j < sz; ++j) ref[y][e[j]] = j;

    for (int j = 1; j < sz; ++j) {
      // cout << e[j] - e[j - 1] << " delta\n";
      lps[y][j] = lps[y][j - 1] + (e[j] - e[j - 1]) * j;
      // cout << "lps: " <<  lps[y][j] << endl;
    }
    for (int j = sz - 2; j >= 0; --j) {
      rps[y][j] = rps[y][j + 1] + (e[j + 1] - e[j]) * (sz - j - 1);
      // cout << "rps: " <<  rps[y][j] << endl;
    }
  }

  ll ans = 0;
  for (int x = 0; x <= 20000; ++x) {
    if (xv[x].empty()) continue;
    auto& e = xv[x];
    sort(e.begin(), e.end());
    
    ll ps = 0;
    int sz = e.size();
    for (int j = 1; j < sz; ++j) {
      ps += (e[j] - e[j - 1]) * j;
      ans += ps * lps[e[j]][ref[e[j]][x]];
      ans %= kMod;
      ans += ps * rps[e[j]][ref[e[j]][x]];
      ans %= kMod;
    }

    ps = 0;
    for (int j = sz - 2; j >= 0; --j) {
      ps += (e[j + 1] - e[j]) * (sz - j - 1);
      ans += ps * lps[e[j]][ref[e[j]][x]];
      ans %= kMod;
      ans += ps * rps[e[j]][ref[e[j]][x]];
      ans %= kMod;
    }
    // cout << ans << "\n";
  }

  cout << ans << "\n";

  return 0;
}