// Fence Painting
// http://www.usaco.org/index.php?page=viewproblem2&cpid=567

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int ans = B - A + D - C;
  if (A < D && B > C) {
    ans -= min(B, D) - max(A, C);
  }

  cout << ans << "\n";

  return 0;
}