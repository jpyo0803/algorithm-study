// Cities and States (Silver)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=667

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<pair<string, string>> v(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i].first >> v[i].second;
  }

  map<string, map<string, int>> cnt;
  for (int i = 0; i < N; ++i) {
    cnt[v[i].second][v[i].first.substr(0, 2)]++;
  }

  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    if (v[i].first.substr(0, 2) == v[i].second) continue;
    ans += (long long)cnt[v[i].first.substr(0, 2)][v[i].second];
  }

  cout << ans / 2 << "\n";

  return 0;
}