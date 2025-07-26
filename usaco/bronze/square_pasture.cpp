// Square Pasture (Bronze)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, e, f, g, h;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> a >> b >> c >> d;
  cin >> e >> f >> g >> h;

  int x1 = min(a, e);
  int y1 = min(b, f);
  int x2 = max(c, g);
  int y2 = max(d, h);
  int s = max(x2 - x1, y2 - y1);
  cout << s * s << "\n";

  return 0;
}