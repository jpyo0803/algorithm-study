// C. Covered Points Count
// https://codeforces.com/problemset/problem/1000/C

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
  for (auto& e : v) cin >> e.first >> e.second;

  vector<ll> cc;
  for (auto e : v) {
    cc.push_back(e.first);
    cc.push_back(e.second + 1);
  }

  sort(cc.begin(), cc.end());
  cc.erase(unique(cc.begin(), cc.end()), cc.end());

  vector<ll> da(2 * n, 0);
  for (auto e : v) {
    int a = distance(cc.begin(), lower_bound(cc.begin(), cc.end(), e.first));
    int b = distance(cc.begin(), lower_bound(cc.begin(), cc.end(), e.second + 1));
    da[a]++;
    da[b]--;
  }

  for (int i = 1; i < 2 * n; ++i) da[i] += da[i - 1];

  vector<ll> ans(n + 1, 0);

  for (int i = 1; i < 2 * n; ++i) {
    if (i >= cc.size()) continue;
    ans[da[i - 1]] += cc[i] - cc[i - 1];
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}