// D. Max Median
// https://codeforces.com/problemset/problem/1486/D?mobile=true

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, k;
int ps[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int lo = 1, hi = 2e5;
  int ans;
  while (lo <= hi) {
    int x = lo + (hi - lo) / 2;

    int lareq = 0, sma = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= x) lareq++;
      else sma++;
      ps[i + 1] = lareq - sma;
    }
    
    int mi = 1e9;
    bool ok = false;
    
    for (int i = k; i <= n; ++i) {
      mi = min(mi, ps[i - k]);
      if (ps[i] - mi > 0) {
        ok = true;
      }
    }
    if (ok) {
      ans = x;
      lo = x + 1;
    } else {
      hi = x - 1;
    }
  }

  cout << ans << "\n";

  return 0;
}