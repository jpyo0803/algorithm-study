// Diamond Collector (Silver)
// https://www.acmicpc.net/problem/12003

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());

  vector<int> r(n);
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j + 1 < n && v[j + 1] - v[i] <= k) j++;
    r[i] = j;
  }

  vector<int> mfr(n);
  for (int i = n - 1; i >= 0; --i) {
    int d = r[i] - i + 1;
    int prev = i + 1 < n ? mfr[i + 1] : 0;
    mfr[i] = max(d, prev);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int ot = r[i] + 1 < n ? mfr[r[i] + 1] : 0;
    ans = max(ans, r[i] - i + 1 + ot);
  }
  cout << ans << "\n";

  return 0;
}