// 창고 다각형
// https://www.acmicpc.net/problem/2304

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<int, int>> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i].first >> vv[i].second;
  sort(vv.begin(), vv.end()); 

  int max_pos;
  int max_height = -1;
  for (int i = 0; i < n; ++i) {
    if (vv[i].second >= max_height) {
      max_height = vv[i].second;
      max_pos = i;
    }
  }

  int ans = 0;

  auto lmp = vv[0];
  for (int i = 0; i <= max_pos; ++i) {
    if (lmp.second <= vv[i].second) {
      ans += (vv[i].first - lmp.first) * lmp.second;
      lmp = vv[i];
    }
  }

  lmp = vv[n - 1];
  for (int i = n - 1; i >= max_pos; --i) {
    if (lmp.second <= vv[i].second) {
      ans += (lmp.first - vv[i].first) * lmp.second;
      lmp = vv[i];
    }
  }
  
  ans += max_height;

  cout << ans << "\n";

  return 0;
}