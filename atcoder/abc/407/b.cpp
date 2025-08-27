// B - P(X or Y) (ABC)
// https://atcoder.jp/contests/abc407/tasks/abc407_b

#include <bits/stdc++.h>

using namespace std;

int x, y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> x >> y;

  int cnt = 0;
  for (int i = 1; i <= 6; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i + j >= x || abs(i - j) >= y) cnt++;
    }
  }

  cout << fixed << setprecision(9) << (double) cnt / 36 << "\n";

  return 0;
}