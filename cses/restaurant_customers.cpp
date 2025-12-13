// Restaurant Customers
// https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> vv(n);
  for (auto& e : vv) cin >> e.first >> e.second;
  sort(vv.begin(), vv.end());

  priority_queue<int> eq;  // keep end time

  int ans = 0;
  for (auto e : vv) {
    while (eq.size() && -eq.top() < e.first) {
      eq.pop();
    }
    eq.push(-e.second);
    ans = max(ans, (int)eq.size());
  }

  cout << ans << "\n";

  return 0;
}