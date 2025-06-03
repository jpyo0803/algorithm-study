// Kayaking
// https://codeforces.com/contest/863/problem/B

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> arr(2 * n);
  for (int i = 0; i < 2 * n; ++i) cin >> arr[i];

  sort(arr.begin(), arr.end());

  int ans = 1e9;
  for (int i = 0; i < 2 * n - 1; ++i) {
    for (int j = i + 1; j < 2 * n; ++j) {
      int cand = 0;
      int last = -1;
      for (int k = 0; k < 2 * n; ++k) {
        if (k == i || k == j) continue;
        if (last == -1) last = arr[k];
        else {
          cand += abs(arr[k] - last);
          last = -1;
        }
      }
      ans = min(ans, cand);
    }
  }

  cout << ans << "\n";

  return 0;
}