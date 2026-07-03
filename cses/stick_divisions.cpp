// Stick Divisions
// https://cses.fi/problemset/task/1161

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  priority_queue<int> pq;

  int x, n;
  cin >> x >> n;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    pq.push(-d);
  }

  ll ans = 0;
  while (pq.size() >= 2) {
    int cost = pq.top();
    pq.pop();
    cost += pq.top();
    pq.pop();
    ans -= cost;
    pq.push(cost);
  }
  cout << ans << "\n";

  return 0;
}