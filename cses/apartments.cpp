// Apartments
// https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int j = 0;
  int ans = 0;
  for (auto e : a) {
    while (j < m && b[j] < e - k) j++;
    if (j == m) break;
    if (b[j] <= e + k) {
      j++;
      ans++;
    }
  }
  cout << ans << "\n";

  return 0;
}