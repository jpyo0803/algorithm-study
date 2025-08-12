// Field Reduction (Silver)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

int n;
bool chosen[50005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<int, int>> cv(n);
  for (int i = 0; i < n; ++i) cin >> cv[i].first >> cv[i].second;
  sort(cv.begin(), cv.end());
  vector<int> lv(4), rv(4), tv(4), bv(4);
  for (int i = 0; i < 4; ++i) {
    lv[i] = cv[i].first;
    rv[i] = cv[n - i - 1].first;
  }
  sort(cv.begin(), cv.end(),
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

  for (int i = 0; i < 4; ++i) {
    bv[i] = cv[i].second;
    tv[i] = cv[n - i - 1].second;
  }

  int ans = 2e9;
  for (auto l : lv) {
    for (auto r : rv) {
      for (auto t : tv) {
        for (auto b : bv) {
          int out_cnt = 0;
          for (auto [x, y] : cv) {
            if (x < l || x > r || y < b || y > t) out_cnt++;
          }
          if (out_cnt > 3) continue;
          ans = min(ans, (r - l) * (t - b));
        }
      }
    }
  }

  cout << ans << "\n";
  return 0;
}