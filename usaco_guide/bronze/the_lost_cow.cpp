// The Lost Cow
// http://www.usaco.org/index.php?page=viewproblem2&cpid=735

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int X, Y;
  cin >> X >> Y;

  int dir = 1;
  int span = 1;

  int ans = 0;
  while (true) {  // Assume it is guaranteed to finish
    int pos = X + dir * span;
    ans += span;
    if (dir == 1) {
      if (Y >= X && pos >= Y) {
        ans -= pos - Y;
        break;
      }
    } else if (dir == -1) {
      if (Y <= X && pos <= Y) {
        ans -= Y - pos;
        break;
      }
    }
    ans += span;
    dir *= -1;
    span *= 2;
  }

  cout << ans << "\n";

  return 0;
}