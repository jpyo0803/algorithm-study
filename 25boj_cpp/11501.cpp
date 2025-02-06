// 주식
// https://www.acmicpc.net/problem/11501

#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;

  while (t--) {
    cin >> n;
    vector<int> vv(n);
    for (int i = 0; i < n; ++i) cin >> vv[i];

    vector<int> partial_max(n);
    int local_max = 0;
    for (int i = n - 1; i >= 0; --i) {
      local_max = max(local_max, vv[i]);
      partial_max[i] = local_max;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (partial_max[i] > vv[i]) {
        ans += partial_max[i] - vv[i];
      }
    }
    cout << ans << "\n";
  }

  return 0;
}