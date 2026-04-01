// C. Yet Another Tournament
// https://codeforces.com/contest/1783/problem/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> av(n);
    for (int i = 0; i < n; ++i) {
      cin >> av[i].first;
      av[i].second = i;
    }

    sort(av.begin(), av.end());

    int lo = 0, hi = n; // # wins

    int ans = 1e9;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int sum = 0;

      bool inc = false;
      for (int i = 0; i < mid; ++i) {
        sum += av[i].first;
        if (mid == av[i].second) inc = true;
      }
      if (sum > m) {
        // impossible
        hi = mid - 1;
      } else {
        int cand = inc ? n - mid : n - mid + 1;
        if (inc == false && mid > 0) {
          sum -= av[mid - 1].first;
          for (int i = mid; i < n; ++i) {
            if (av[i].second != mid) continue;
            if (sum + av[i].first <= m) {
              cand = n - mid;
            }
          }
        }

        ans = min(ans, cand);
        lo = mid + 1;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}