// Counting Liars
// http://usaco.org/index.php?page=viewproblem2&cpid=1228

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<pair<char, int>> cows(N);
  for (int i = 0; i < N; ++i) {
    cin >> cows[i].first >> cows[i].second;
  }

  int ans = 1e9;
  for (int i = 0; i < N; ++i) {
    int cnt = 0;
    for (int j = 0; j < N; ++j) {
      if (i == j) continue; // not necessary but is there for exactness
      if (cows[j].first == 'G') {
        if (cows[i].second < cows[j].second) cnt++;
      } else {
        if (cows[i].second > cows[j].second) cnt++;
      }
    }
    ans = min(ans, cnt);
  }

  cout << ans << "\n";

  return 0;
}