// Sum of Two Values
// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>

using namespace std;

int n, x, a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> x;

  vector<pair<int, int>> vv(n);
  for (int i = 0; i < n; ++i) {
    cin >> vv[i].first;
    vv[i].second = i;
  }

  sort(vv.begin(), vv.end());

  int l = 0, r = vv.size() - 1;
  int sum = vv[l].first + vv[r].first;
  int ans1 = -1, ans2;
  while (l < r) {
    if (sum == x) {
      ans1 = vv[l].second + 1;
      ans2 = vv[r].second + 1;
      break;
    } else if (sum < x) {
      l++;
      sum = vv[l].first + vv[r].first;
    } else {
      r--;
      sum = vv[l].first + vv[r].first;
    }
  }

  if (ans1 == -1) cout << "IMPOSSIBLE\n";
  else cout << ans1 << " " << ans2 << "\n";

  return 0;
}