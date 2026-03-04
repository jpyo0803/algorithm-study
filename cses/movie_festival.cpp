// Movie Festival
// https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i].second >> vv[i].first;

  sort(vv.begin(), vv.end());
  int ans = 0;
  int last_end = -1;
  for (int i = 0; i < n; ++i) {
    if (last_end == -1) {
      ans++;
      last_end = vv[i].first;
    } else if (last_end <= vv[i].second) {
      ans++;
      last_end = vv[i].first;
    }
  }
  cout << ans << "\n";

  return 0;
}