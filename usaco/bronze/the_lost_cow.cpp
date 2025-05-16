// The Lost Cow (Bronze)
// https://www.acmicpc.net/problem/14530

#include <bits/stdc++.h>

using namespace std;

int x, y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> x >> y;

  int w = 1;
  int ans = 0;
  while (true) {
    int pos = x + w;
    if (min(x, pos) <= y && y <= max(x, pos)) {
      ans += abs(x - y);
      break;
    }
    ans += abs(2 * w);
    w *= -2;
  }

  cout << ans << "\n";

  return 0;
}