// Shell Game
// http://www.usaco.org/index.php?page=viewproblem2&cpid=891

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  int track[3] = {0, 1, 2};
  int cnt[3] = {0, 0, 0};

  for (int i = 0; i < n; ++i) {
    int a, b, g;
    cin >> a >> b >> g;

    --a, --b, --g;
    swap(track[a], track[b]);
    ++cnt[track[g]];
  }

  cout << max({cnt[0], cnt[1], cnt[2]}) << "\n";

  return 0;
}