// Sleeing in Class (Bronze)
// https://www.acmicpc.net/problem/24620

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
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      sum += v[i];
    }

    int ans;
    for (int d = n; d >= 1; d--) {
      if (sum % d == 0) {
        // Assume sum % d is sparsely 0
        // if every sum % d == 0, that means sum = 1 * 2 * 3 * ... *d,
        // but it is guaranteed that sum <= 1e6, which means 9! <= sum <= 10!,
        // that is for each sum at most 10 clean division is possible. O(10 *
        // 1e5)
        // From editorial, it says maximum # of divisors of any number <= 1e6 is 240

        int target = sum / d;
        int local_sum = 0;

        bool ok = true;
        for (int i = 0; i < n; ++i) {
          local_sum += v[i];
          if (local_sum == target) {
            local_sum = 0;
          } else if (local_sum > target) {
            ok = false;
            break;
          }
        }
        if (!ok) continue;

        ans = n - d;
        break;
        // break if found
      }
    }
    cout << ans << "\n";
  }

  return 0;
}