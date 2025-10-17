// Quiz Master
// https://codeforces.com/contest/1777/problem/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<int> f[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // O(1e6) as 1e5 * (1/2 + 1/4 + ... + 1/100000)
  for (int i = 1; i <= 1e5; ++i) {
    for (int j = i; j <= 1e5; j += i) f[j].push_back(i);
  }

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
  
    vector<int> cov(m + 1, 0);
    int cov_cnt = 0;

    int l = 0, r = -1;
    int ans = 1e9;
    while (r < n) {
      if (cov_cnt < m) {
        // expand
        if (r + 1 == n) break;
        for (auto e : f[a[r + 1]]) {
          if (e > m) break;
          if (cov[e] == 0) cov_cnt++;
          cov[e]++;
        }
        r++;
      } else {
        // shrink
        if (l + 1 == n) break;
        for (auto e : f[a[l]]) {
          if (e > m) break;
          if (cov[e] == 1) cov_cnt--;
          cov[e]--;
        }
        l++;
      }

      if (cov_cnt == m) ans = min(ans, a[r] - a[l]);
    }
    if (ans == 1e9) cout << "-1\n";
    else cout << ans << "\n";
  }

  return 0;
}