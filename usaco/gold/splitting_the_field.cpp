// Splitting the Field (Gold)
// https://www.acmicpc.net/problem/12011

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

ll Solve(vector<pair<int, int>>& pts) {
  sort(pts.begin(), pts.end());

  vector<pair<int, int>> pref(n), suf(n);
  pref[0] = {pts[0].second, pts[0].second},
  suf[n - 1] = {pts.back().second, pts.back().second};

  for (int i = 1; i < n; ++i) {
    pref[i].first = min(pref[i - 1].first, pts[i].second);
    pref[i].second = max(pref[i - 1].second, pts[i].second);
  }

  for (int i = n - 2; i >= 0; --i) {
    suf[i].first = min(suf[i + 1].first, pts[i].second);
    suf[i].second = max(suf[i + 1].second, pts[i].second);
  }

  ll total_area = (ll)(pts.back().first - pts[0].first) *
                  (pref[n - 1].second - pref[n - 1].first);

  ll ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (pts[i].first != pts[i + 1].first) {
      ll a1 =
          (ll)(pts[i].first - pts[0].first) * (pref[i].second - pref[i].first);
      ll a2 = (ll)(pts[n - 1].first - pts[i + 1].first) *
              (suf[i + 1].second - suf[i + 1].first);
      ans = max(ans, total_area - (a1 + a2));
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  vector<pair<int, int>> pts(n);
  for (int i = 0; i < n; ++i) cin >> pts[i].first >> pts[i].second;

  ll ans = 0;
  ans = max(ans, Solve(pts));

  for (auto& e : pts) swap(e.first, e.second);
  ans = max(ans, Solve(pts));

  cout << ans << "\n";

  return 0;
}