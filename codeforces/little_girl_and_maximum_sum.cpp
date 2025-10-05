// C. Little Girl and Maximum Sum
// https://codeforces.com/contest/276/problem/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  vector<int> av(n), da(n + 1);
  for (int i = 0; i < n; ++i) cin >> av[i];
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    da[l - 1]++, da[r]--;
  }

  for (int i = 1; i <= n; ++i) da[i] += da[i - 1];

  sort(av.begin(), av.end());
  sort(da.begin(), da.end());

  ll ans = 0;
  for (int i = 0; i < n; ++i) ans += (ll) da[i + 1] * av[i];
  cout << ans << "\n";

  return 0;
}