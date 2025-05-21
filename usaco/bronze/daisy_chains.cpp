// Daisy Chains (Bronze)
// https://www.acmicpc.net/problem/20651

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> p(n);

  int ans = 0;
  for (int i = 0; i < n; ++i) cin >> p[i];

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int sum = 0;
      for (int k = i; k <= j; ++k) {
        sum += p[k];
      }

      bool ok = false;
      for (int k = i; k <= j; ++k) {
        if (sum == p[k] * (j - i + 1)) {
          ok = true;
        }
      }
      if (ok) ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}