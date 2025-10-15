// Cellular Network
// https://codeforces.com/contest/702/problem/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> av(n), bv(m);
  for (auto& e : av) cin >> e;
  for (auto& e : bv) cin >> e;

  int x = 0, y = 0;
  int ans = 0;
  while (x < n) {
    while (y < m && av[x] > bv[y]) y++;
    int l = y - 1 >= 0 ? abs(av[x] - bv[y - 1]) : 2e9;
    int r = y < m ? abs(av[x] - bv[y]) : 2e9;
    ans = max(ans, min(l, r));
    x++;
  }
  cout << ans << "\n";

  return 0;
}