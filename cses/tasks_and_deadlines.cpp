// Tasks and Deadlines
// https://cses.fi/problemset/task/1630

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());

  ll t = 0;
  ll ans = 0;
  for (auto [a, d] : v) {
    t += a;
    ans += d - t;
  }
  cout << ans << "\n";
  
  return 0;
}