// Rest Stops (Silver)
// https://www.acmicpc.net/problem/15748

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int L, n, f, b;
  cin >> L >> n >> f >> b;

  vector<pair<int, int>> vv;
  for (int i = 0; i < n; ++i) {
    int x, c;
    cin >> x >> c;
    vv.emplace_back(x, c);
  }

  sort(vv.begin(), vv.end());
  set<pair<int, int>> ss;
  for (auto e : vv) ss.insert({-e.second, e.first});

  int pos = 0;  // john pos
  ll ans = 0;
  int i = 0;
  while (true) {
    while (i < n) {
      if (vv[i].first <= pos) {
        ss.erase(ss.find({-vv[i].second, vv[i].first}));
        i++;
      } else {
        break;
      }
    }

    if (ss.empty()) break;

    auto it = ss.begin();
    int x = it->second;  // targ pos
    int c = -(it->first);

    ll dtf = (ll)(x - pos) * f;
    ll dtb = (ll)(x - pos) * b;
    ll dt = dtf - dtb;
    ans += dt * c;
    pos = x;
  }

  cout << ans << "\n";

  return 0;
}