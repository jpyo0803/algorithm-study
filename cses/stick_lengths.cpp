// Stick Lengths
// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());

  int med = v[n / 2];
  ll ans = 0;
  for (auto e : v) ans += abs(med - e);
  cout << ans << "\n";

  return 0;
}