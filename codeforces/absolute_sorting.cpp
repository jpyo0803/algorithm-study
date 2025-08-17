// D. Absolute Sorting
// https://codeforces.com/contest/1772/problem/D

#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int hi = 1e9;
    int lo = 0;

    for (int i = 0; i < n - 1; ++i) {
      if (a[i] > a[i + 1]) {
        int x = (a[i] + a[i + 1] + 1) / 2;  // at least
        lo = max(lo, x);
      } else if (a[i] < a[i + 1]) {
        int x = (a[i] + a[i + 1]) / 2;  // at most
        hi = min(hi, x);
      }
    }
    if (lo > hi)
      cout << "-1\n";
    else
      cout << lo << "\n";
  }

  return 0;
}