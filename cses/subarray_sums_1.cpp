// Subarray Sums I
// https://cses.fi/problemset/task/1660

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> av(n);
  for (int i = 0; i < n; ++i) cin >> av[i];

  int sum = 0;
  int ans = 0;
  int l = 0, r = -1;
  while (true) {
    if (sum <= x) {
      if (r + 1 == n) break;
      sum += av[++r];
    } else if (sum > x) {
      sum -= av[l++];
    }
    if (sum == x) ans++;
  }

  cout << ans << "\n";

  return 0;
}