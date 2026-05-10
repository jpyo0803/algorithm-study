// E. William and Robot
// https://codeforces.com/gym/104002/problem/E

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    pq.push(-a[i]);
    if (i % 2 && pq.size() > (i + 1) / 2) {
      pq.pop();
    }
  }

  ll ans = 0;
  while (pq.size()) {
    ans -= pq.top();
    pq.pop();
  }

  cout << ans << "\n";

  return 0;
}