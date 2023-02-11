// Load Balancing (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=617

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, B;
  cin >> N >> B;

  vector<pair<int, int>> cows(N);
  vector<int> xpos, ypos;
  for (int i = 0; i < N; ++i) {
    cin >> cows[i].first >> cows[i].second;
    xpos.push_back(cows[i].first);
    ypos.push_back(cows[i].second);
  }

  sort(xpos.begin(), xpos.end());
  sort(ypos.begin(), ypos.end());

  vector<int> x_cand, y_cand;
  x_cand.push_back(xpos[0] - 1);
  y_cand.push_back(ypos[0] - 1);

  for (int i = 0; i < xpos.size() - 1; ++i) {  // interpolation
    x_cand.push_back((xpos[i] + xpos[i + 1]) / 2);
    y_cand.push_back((ypos[i] + ypos[i + 1]) / 2);
  }

  x_cand.push_back(xpos.back() + 1);
  y_cand.push_back(ypos.back() - 1);

  int ans = 1e9;
  for (auto a : x_cand) {    // x = a
    for (auto b : y_cand) {  // y = b
      int q1 = 0, q2 = 0, q3 = 0,
          q4 = 0;  // quadrant from 1 ~ 4
      for (auto& [x, y] : cows) {
        if (x > a && y > b)
          q1++;
        else if (x < a && y > b)
          q2++;
        else if (x < a && y < b)
          q3++;
        else
          q4++;
      }
      ans = min(ans, max({q1, q2, q3, q4}));
    }
  }
  cout << ans << "\n";

  return 0;
}