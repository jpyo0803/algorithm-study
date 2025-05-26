// Load Balancing (Silver)
// https://www.acmicpc.net/problem/11997

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<int, int>> cows(n);
  for (int i = 0; i < n; ++i) {
    cin >> cows[i].first >> cows[i].second;
  }

  sort(cows.begin(), cows.end());

  vector<int> xs, ys;
  xs.push_back(0);
  ys.push_back(0);
  for (auto [x, y] : cows) {
    xs.push_back(x + 1);
    ys.push_back(y + 1);
  }

  int ans = 1e9;
  // be careful of duplicate x's
  for (auto b : ys) {
    int q1 = 0;
    int q2 = 0;
    int q3 = 0;
    int q4 = 0;

    for (auto [cow_x, cow_y] : cows) {
      if (cow_y > b)
        q1++;
      else
        q4++;
    }

    ans = min(ans, max({q1, q2, q3, q4}));

    int cow_idx = 0;
    for (auto a : xs) {
      while (cow_idx < n && cows[cow_idx].first < a) {
        int cow_x, cow_y;
        tie(cow_x, cow_y) = cows[cow_idx];
        if (cow_y > b) {
          q1--;
          q2++;
        } else {
          q4--;
          q3++;
        }
        cow_idx++;
      }

      ans = min(ans, max({q1, q2, q3, q4}));
    }
  }

  cout << ans << "\n";

  return 0;
}