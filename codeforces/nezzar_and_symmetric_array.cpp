// Nezzar and Symmetric Array
// https://codeforces.com/problemset/problem/1478/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<ll> d(2 * n);
    for (int i = 0; i < 2 * n; ++i) cin >> d[i];
    
    sort(d.begin(), d.end());
    
    bool ok = true;
    for (int i = 0; i < 2 * n; i += 2) {
      if (d[i] != d[i + 1]) ok = false;
    }
    
    vector<ll> dd(n);
    for (int i = 0; i < n; ++i) dd[i] = d[i * 2];

    for (int i = 0; i < n - 1; ++i) {
      if (dd[i] == dd[i + 1]) ok = false;
    }

    vector<ll> a(n);
    if ((dd[n - 1] % (2 * n)) != 0) ok = false;
    a[n - 1] = dd[n - 1] / (2 * n);
    for (int i = n - 2; i >= 0; --i) {
      ll ddd = dd[i] - dd[i + 1] + 2 * (i + 1) * a[i + 1];
      if (ddd % (2 * (i + 1))) ok = false;
      a[i] = ddd / (2 * (i + 1));
    }

    if (a[0] <= 0) ok = false;

    cout << (ok ? "YES" : "NO") << "\n";
  }

  return 0;
}