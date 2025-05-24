// Load Balancing (Bronze)
// https://www.acmicpc.net/problem/12001

#include <bits/stdc++.h>

using namespace std;

int n, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> b;
  vector<pair<int, int>> cows(n);
  for (int i = 0; i < n; ++i) cin >> cows[i].first >> cows[i].second;

  sort(cows.begin(), cows.end(),
       [](const pair<int, int>& x, const pair<int, int>& y) {
         return x.first < y.first;
       });

  vector<int> av;
  av.push_back(0);
  for (int i = 0; i < n - 1; ++i) {
    int mid = (cows[i].first + cows[i + 1].first) / 2;
    av.push_back(mid);
  }

  sort(cows.begin(), cows.end(),
       [](const pair<int, int>& x, const pair<int, int>& y) {
         return x.second < y.second;
       });

  vector<int> bv;
  bv.push_back(0);
  for (int i = 0; i < n - 1; ++i) {
    int mid = (cows[i].second + cows[i + 1].second) / 2;
    bv.push_back(mid);
  }

  int ans = 1e9;
  for (auto a : av) {
    for (auto b : bv) {  // 10000
      int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
      for (auto [x, y] : cows) {
        if (x > a && y > b)
          q1++;
        else if (x < a && y > b)
          q2++;
        else if (x < a && y < b)
          q3++;
        else
          q4++;
      }

      ans = min(ans, max(q1, max(q2, max(q3, q4))));
    }
  }

  cout << ans << "\n";

  return 0;
}