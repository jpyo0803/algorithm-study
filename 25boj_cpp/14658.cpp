// 하늘에서 별똥별이 빗발친다
// https://www.acmicpc.net/problem/14658

#include <bits/stdc++.h>

using namespace std;

int n, m, l, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> l >> k;

  vector<pair<int, int>> vv(k);
  for (int i = 0; i < k; ++i) cin >> vv[i].first >> vv[i].second;

  int ans = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      int xref = vv[i].first;
      int yref = vv[j].second;
      int cnt = 0;
      for (int ii = 0; ii < k; ++ii) {
        if (xref <= vv[ii].first && vv[ii].first <= xref + l &&
            yref <= vv[ii].second && vv[ii].second <= yref + l) {
          cnt++;
          // cout << vv[ii].first << " / " << vv[ii].second << endl;
        }
      }
      // cout << "---------------------" << endl;
      ans = max(ans, cnt);
    }
  }

  cout << k - ans << "\n";

  return 0;
}