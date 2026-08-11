// F1. Survival of the Weakest (easy version)
// https://codeforces.com/problemset/problem/1805/F1

#include <bits/stdc++.h>

#define ll long long

using namespace std;

constexpr int kMod = 1000000007;

ll Pow2(ll exp) {
  if (exp == 0) return 1;
  ll ret = Pow2(exp / 2);
  ret *= ret;
  if (exp % 2) ret *= 2;
  ret %= kMod;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<ll> vv(n);
  for (auto& e : vv) cin >> e;

  sort(vv.begin(), vv.end());

  ll c = 0;
  int m = n;
  while (--m > 0) {
    ll min_val = vv[0];
    for (auto& e : vv) e -= min_val;
    c = (c + min_val * Pow2(m)) % kMod;

    priority_queue<pair<ll, int>> pq;
    vector<int> next(m);

    for (int i = 0; i < m; ++i) next[i] = i + 1;
    for (int i = 0; i < m; ++i) {
      pq.emplace(-(vv[i] + vv[next[i]]), i);
      next[i]++;
    }
    vector<ll> vv2;
    int mm = m;
    while (mm--) {
      int idx = pq.top().second;
      vv2.push_back(-pq.top().first);
      pq.pop();
      if (next[idx] < vv.size()) pq.emplace(-(vv[idx] + vv[next[idx]]), idx);
      next[idx]++;
    }
    vv.swap(vv2);
  }
  cout << (vv[0] + c) % kMod << "\n";

  return 0;
}