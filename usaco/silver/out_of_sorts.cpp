// Out of Sorts (Silver)
// https://www.acmicpc.net/problem/15760

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> vv;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    vv.emplace_back(x, i);
  }

  sort(vv.begin(), vv.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, vv[i].second - i);
  }

  cout << ans + 1 << "\n";

  return 0;
}