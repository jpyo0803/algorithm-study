// Two Tables (CF)
// https://codeforces.com/problemset/problem/1555/B

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

    int ans = -1;
    // glue it below
    int d = y1 - h;
    if (d >= 0) {
      ans = 0;
    } else if (y2 - d <= H) {
      if (ans == -1 || -d < ans) {
        ans = -d;
      }
    }

    // glue it above
    d = y2 + h;
    if (d <= H) {
      ans = 0;
    } else if (d - H <= y1) {
      if (ans == -1 || d - H < ans) {
        ans = d - H;
      }
    }

    // glue it left
    d = x1 - w;
    if (d >= 0) {
      ans = 0;
    } else if (x2 - d <= W) {
      if (ans == -1 || -d < ans) {
        ans = -d;
      }
    }

    // glue it right
    d = x2 + w;
    if (d <= W) {
      ans = 0;
    } else if (d - W <= x1) {
      if (ans == -1 || d - W < ans) {
        ans = d - W;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}