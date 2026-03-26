// Bovine Acrobatics (Silver)
// https://www.acmicpc.net/problem/31060

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<pair<int, int>> cv(n);
  for (int i = 0; i < n; ++i) cin >> cv[i].first >> cv[i].second;
  sort(cv.rbegin(), cv.rend());

  queue<pair<int, int>> que;
  que.emplace(2e9, m);

  int i = 0;
  ll ans = 0;
  while (true) {
    auto& f = que.front();
    while (i < n && f.first - cv[i].first < k) i++;
    if (i == n) break;

    int amt = min(f.second, cv[i].second);
    f.second -= amt;
    cv[i].second -= amt;
    if (f.second == 0) que.pop();
    
    if (que.empty()) {
      que.emplace(cv[i].first, amt);
    } else {
      if (que.back().first == cv[i].first) que.back().second += amt;
      else que.emplace(cv[i].first, amt);
    }

    if (cv[i].second == 0) i++;

    ans += amt;
  }
  cout << ans << "\n";

  return 0;
}