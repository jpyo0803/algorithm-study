// E - Most Valuable Parentheses (ABC)
// https://atcoder.jp/contests/abc407/tasks/abc407_e

#include <bits/stdc++.h>

using namespace std;

int t;

int a[400005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < 2 * n; ++i) cin >> a[i];

    priority_queue<int> pq;

    long long ans = a[0];
    for (int i = 1; i < n; ++i) {
      pq.push(a[i * 2 - 1]);
      pq.push(a[i * 2]);

      ans += pq.top();
      pq.pop();
    }

    cout << ans << "\n";
  }

  return 0;
}