// Static Range Sum
// https://judge.yosupo.jp/problem/static_range_sum

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, q;
ll ps[500005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> ps[i];
    ps[i] += ps[i - 1];
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << ps[r] - ps[l] << "\n";
  }

  return 0;
}