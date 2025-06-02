// Playing in a Casino
// https://codeforces.com/contest/1808/problem/B

#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> arr[j][i];
      }
    }

    long long ans = 0;

    for (int i = 0; i < m; ++i) {
      sort(arr[i].begin(), arr[i].end());
      long long sum = 0;
      for (int j = 0; j < n; ++j) {
        ans += (long long)j * arr[i][j] - sum;
        sum += arr[i][j];
      }
    }
    cout << ans << "\n";
  }

  return 0;
}