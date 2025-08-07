// C. Quests
// https://codeforces.com/problemset/problem/1914/C

#include <bits/stdc++.h>

using namespace std;

int t, n, k;
int a[200005];
int b[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int ans = 0;
    int sum = 0;
    int max_b = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      max_b = max(max_b, b[i]);
      int rem_k = k - (i + 1);
      if (rem_k >= 0) {
        ans = max(ans, sum + rem_k * max_b);
      }
    }

    cout << ans << "\n";
  }

  return 0;
}