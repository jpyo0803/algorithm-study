// Lifeguards (Bronze)
// https://www.acmicpc.net/problem/15593

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<int, int>> tv(n);
  for (int i = 0; i < n; ++i) cin >> tv[i].first >> tv[i].second;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    // exclude i

    vector<bool> cv(1001, false);
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      int t1 = tv[j].first + 1, t2 = tv[j].second;
      for (int k = t1; k <= t2; ++k) {
        cv[k] = true;
      }
    }
    int cand = 0;
    for (int j = 1; j <= 1000; ++j) {
      if (cv[j]) cand++;
    }
    ans = max(ans, cand);
  }

  cout << ans << "\n";

  return 0;
}