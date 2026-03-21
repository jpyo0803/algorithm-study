// A. The Party and Sweets
// https://codeforces.com/problemset/problem/1158/A

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> bv(n), gv(m);

  for (int i = 0; i < n; ++i) cin >> bv[i];
  for (int i = 0; i < m; ++i) cin >> gv[i];

  sort(bv.rbegin(), bv.rend());
  sort(gv.rbegin(), gv.rend());

  if (gv.back() < bv[0]) {
    cout << "-1\n";
    return 0;
  }

  ll ans = 0;

  int i = 0, j = 0;
  int cnt = 0;
  bool ok = true;
  while (i < n && j < m) {
    int b = bv[i];
    int g = gv[j];
    if (j == m - 1) {
      if (b == g) {
        ans += g;
        i++;
      } else {
        ans += b;
        i++;
        if (i == n)
          ok = false;
        else {
          if (bv[i] <= g) {
            ans += g;
            ans += (ll)bv[i] * (m - 1);
            // cout << "ans : " << ans << endl;
            i++;
          } else {
            ok = false;
          }
        }
      }
      break;
    } else {
      if (b <= g) {
        ans += g;
        j++;
        cnt++;
      } else {
        ans += (ll)b * (m - cnt);
        i++;
        cnt = 0;
      }
    }
  }

  while (i < n) {
    ans += (ll)bv[i] * m;
    i++;
  }

  cout << (ok ? ans : -1) << "\n";

  return 0;
}