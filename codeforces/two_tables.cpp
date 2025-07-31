// B. Two Tables
// https://codeforces.com/problemset/problem/1555/B

#include <bits/stdc++.h>

using namespace std;

int t;
int W, H;
int w, h;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> W >> H;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;

    int ans = 1e9;

    {
      if (x2 - x1 + w <= W) {
        ans = min(ans, w - x1);
        ans = min(ans, x2 - (W - w));
      }
      if (y2 - y1 + h <= H) {
        ans = min(ans, h - y1);
        ans = min(ans, y2 - (H - h));
      }
    }
    if (ans == 1e9)
      cout << "-1\n";
    else
      cout << max(ans, 0) << "\n";
  }

  return 0;
}