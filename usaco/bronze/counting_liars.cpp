// Counting Liars (Bronze)
// https://www.acmicpc.net/problem/24981

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<char, int>> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

  int ans = 1e9;
  for (int i = 0; i < n; ++i) {
    int bessie = v[i].second;
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      char dir;
      int pos;
      tie(dir, pos) = v[j];
      if (dir == 'L') {
        if (pos < bessie) cnt++;
      } else {
        if (pos > bessie) cnt++;
      }
    }
    ans = min(ans, cnt);
  }

  cout << ans << "\n";

  return 0;
}