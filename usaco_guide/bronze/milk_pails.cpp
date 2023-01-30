// Milk Pails
// http://www.usaco.org/index.php?page=viewproblem2&cpid=615

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int X, Y, M;
  cin >> X >> Y >> M;

  int ans = 0;
  int xamt = 0;

  while (true) {
    xamt += X;
    int yamt = ((M - xamt) / Y) * Y;
    int total_amt = xamt + yamt;
    if (total_amt > M) break;
    ans = max(ans, total_amt);
  }

  cout << ans << "\n";

  return 0;
}