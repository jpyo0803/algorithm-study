// Rectangular Pasture (Silver)
// https://www.acmicpc.net/problem/20648

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
int arr[2505][2505];
int ps[2505][2505];

int GetCnt(int x1, int y1, int x2, int y2) {
  return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  vector<pair<int, int>> cv(n);
  for (int i = 0; i < n; ++i) cin >> cv[i].first >> cv[i].second;

  sort(cv.begin(), cv.end());
  for (int i = 1; i <= n; ++i) cv[i - 1].first = i;
  sort(cv.begin(), cv.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
  });
  for (int i = 1; i <= n; ++i) cv[i - 1].second = i;

  for (auto e : cv) arr[e.first][e.second] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ps[i][j] = arr[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
    }
  }

  ll ans = n + 1;
  for (int i = 0; i < cv.size(); ++i) {
    for (int j = i + 1; j < cv.size(); ++j) {
      int yl = min(cv[i].second, cv[j].second);
      int yr = max(cv[i].second, cv[j].second);
      int xt = min(cv[i].first, cv[j].first);
      int xb = max(cv[i].first, cv[j].first);

      ll a = GetCnt(1, yl, xt - 1, yr);
      ll b = GetCnt(xb + 1, yl, n, yr);
      ans += (a + 1) * (b + 1);
    }
  }

  cout << ans << "\n";

  return 0;
}