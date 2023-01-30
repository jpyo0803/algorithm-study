// Maximum Distance (CF)
// https://codeforces.com/gym/102951/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<pair<int, int>> coords(N);
  for (int i = 0; i < N; ++i) {
    cin >> coords[i].first;
  }
  for (int i = 0; i < N; ++i) {
    cin >> coords[i].second;
  }

  int ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int dx = coords[i].first - coords[j].first;
      int dy = coords[i].second - coords[j].second;

      ans = max(ans, dx * dx + dy * dy);
    }
  }

  cout << ans << "\n";

  return 0;
}