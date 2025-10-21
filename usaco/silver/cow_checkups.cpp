// Cow Checkups (Silver)
// https://www.acmicpc.net/problem/33504

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll Choose2(ll n) {
  return n * (n + 1) / 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) continue;
    ans += Choose2(i) + Choose2(n - i - 1) + min(i, n - i - 1) + 1;
  }

  for (int ii = 0; ii < 2; ++ii) {
    vector<vector<pair<int, int>>> vv(n + 1);
    for (int i = 0; i < n; ++i) {
      vv[b[i]].emplace_back(i, 1);
      vv[a[i]].emplace_back(i, 0);
    }

    for (int v = 1; v <= n; ++v) {
      auto& tv = vv[v];
      reverse(tv.begin(), tv.end());
      
      stack<int> stk;
      int cnt = 0;
      ll sum = 0;
      for (auto e : tv) {
        int idx = e.first;
        int type = e.second;

        if (type == 0) { // a
          int span = idx + 1; 
          // remove span by 'b' larger than me
          while (stk.size() && stk.top() > span) {
            cnt++;
            sum -= stk.top();
            stk.pop();
          }
          ans += sum + (ll)cnt * span;
        } else { // b
          int span = n - idx; // wing span including self
          sum += span;
          stk.push(span);
        }
      }
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
  }
  cout << ans << "\n";

  return 0;
}