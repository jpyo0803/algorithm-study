// Milk Pails (Bronze)
// https://www.acmicpc.net/problem/11999

#include <bits/stdc++.h>

using namespace std;

int x, y, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> x >> y >> m;
  
  int ans = 0;
  for (int i = 0; i <= 1000; ++i) {
    for (int j = 0; j <= 1000; ++j) {
      int amt = x * i + y * j;
      if (amt > m) continue;
      ans = max(ans, amt);
    }
  }

  cout << ans << "\n";

  return 0;
}