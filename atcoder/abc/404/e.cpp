// E - Bowls and Beans (ABC)
// https://atcoder.jp/contests/abc404/tasks/abc404_e

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
int c[2005];
int a[2005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i < n; ++i) cin >> c[i];
  for (int i = 1; i < n; ++i) cin >> a[i];
  
  int ans = 0;
  int frontier = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] == 1) {
      int l = i, r = i;

      while (frontier < l) {
        ans++;
        int nl = 1e9;
        for (int j = l; j <= r; ++j) {
          nl = min(nl, j - c[j]);
        }
        l = nl;
      }
      frontier = i;
    }
  }

  cout << ans << "\n";

  return 0;
}