// 덩치
// https://www.acmicpc.net/problem/7568

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> vv;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    vv.emplace_back(x, y);
  }

  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (vv[j].first > vv[i].first && vv[j].second > vv[i].second) {
        cnt++;
      }
    }
    cout << cnt + 1 << " ";
  }
  cout << "\n";

  return 0;
}