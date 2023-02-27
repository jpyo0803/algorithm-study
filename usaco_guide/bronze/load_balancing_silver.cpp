// Load Balancing (Silver)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=619

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<pair<int, int>> cows(N);
  cows.emplace_back(1e9, 1e9);

  for (int i = 0; i < cows.size(); ++i) {
    cin >> cows[i].first >> cows[i].second;
  }

  vector<int> xind, yind;
  for (int i = 0; i < cows.size(); ++i) {
    xind.push_back(i);
    yind.push_back(i);
  }

  sort(xind.begin(), xind.end(),
       [&](int a, int b) { return cows[a].first < cows[b].first; });
  sort(yind.begin(), yind.end(),
       [&](int a, int b) { return cows[a].second < cows[b].second; });

  int ans = 1e9;
  int i = 0;
  while (i < xind.size()) {
    int q1 = N - i, q2 = i, q3 = 0, q4 = 0;

    int j = 0;
    while (j < yind.size()) {
      while (j + 1 < yind.size() &&
             cows[yind[j]].second == cows[yind[j + 1]].second) {
        if (cows[yind[j]].first < cows[xind[i]].first) {
          --q2;
          ++q3;
        } else {
          --q1;
          ++q4;
        }
        ++j;
      }
      if (cows[yind[j]].first < cows[xind[i]].first) {
        --q2;
        ++q3;
      } else {
        --q1;
        ++q4;
      }
      ++j;

      ans = min(ans, max({q1, q2, q3, q4}));
    }

    while (i + 1 < xind.size() &&
           cows[xind[i]].first == cows[xind[i + 1]].first) {
      ++i;
    }
    ++i;
  }

  cout << ans << "\n";

  return 0;
}