// Maximum Distance
// https://codeforces.com/gym/102951/problem/A

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < n; ++i) cin >> y[i];

  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      ans = max(ans, dx * dx + dy * dy);
    }
  }

  cout << ans << "\n";

  return 0;
}