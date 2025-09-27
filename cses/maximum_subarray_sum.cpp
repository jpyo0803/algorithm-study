// Maximum Subarray Sum
// https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  ll sum = 0;

  ll ans = -1e18;
  ll mi = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum += x;
    ans = max({ans, sum - mi});
    mi = min(mi, sum);
  }
  cout << ans << "\n";

  return 0;
}