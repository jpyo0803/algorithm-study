// D - Domino Covering XOR (ABC)
// https://atcoder.jp/contests/abc407/tasks/abc407_d

#include <bits/stdc++.h>

using namespace std;

int h, w;
long long a[20][20];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
    }
  }

  vector<int> cv; // configurations
  cv.push_back(0); // no dominos

  int hd = 3, vd = (1 << w) + 1;

  int b = 0;
  while (b < h * w) {
    int x = b / w, y = b % w;

    vector<int> tmp;
    for (auto c : cv) {
      if (y + 1 < w && (c & (hd << b)) == 0) {
        tmp.push_back(c | (hd << b));
      }
      if (x + 1 < h && (c & (vd << b)) == 0) {
        tmp.push_back(c | (vd << b));
      }
    }
    for (auto e : tmp) cv.push_back(e);
    b++;
  }

  long long ans = 0;
  
  for (auto c : cv) {
    int b = 0;

    long long cand = 0;
    while (b < h * w) {
      if (((c >> b) & 1) == 0) {
        cand  ^= a[b / w][b % w];
      }
      b++;
    }

    ans = max(ans, cand);
  }

  cout << ans << "\n";

  return 0;
}