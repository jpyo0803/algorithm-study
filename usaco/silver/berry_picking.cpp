// Berry Picking (Silver)
// https://www.acmicpc.net/problem/18319

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> bv(n);
  for (int i = 0; i < n; ++i) cin >> bv[i];
  int ma = 0;
  for (auto e : bv) ma = max(ma, e);

  int ans = 0;
  for (int b = 1; b <= ma; ++b) {
    priority_queue<int> pq;
    int cnt = 0;
    for (auto e : bv) {
      cnt += e / b;
      pq.push(e % b);
    }
    if (cnt < k / 2) continue;
    else if (cnt >= k) ans = max(ans, b * k / 2);
    else {
      // k / 2 <= cnt < k
      int cand = b * (cnt - k / 2);
      int rem = k - cnt;
      while (rem-- && pq.size()) {
        cand += pq.top();
        pq.pop();
      }
      ans = max(ans, cand);
    }
  }

  cout << ans << "\n";

  return 0;
}