// High Card Wins (Silver)
// https://www.acmicpc.net/problem/11968

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<bool> used(2 * n + 1);
  vector<int> ev(n);
  for (int i = 0; i < n; ++i) {
    cin >> ev[i];
    used[ev[i]] = true;
  }

  set<int> bs;
  for (int i = 1; i <= 2 * n; ++i) {
    if (used[i] == false) bs.insert(i);
  }

  int ans = 0;
  for (auto ec : ev) {
    auto it = bs.upper_bound(ec);
    if (it == bs.end()) continue;
    bs.erase(it);
    ans++;
  }
  cout << ans << "\n";

  return 0;
}