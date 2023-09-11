// Even More Odd Photos
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1084

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  int odd = 0, even = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    if (x % 2 == 0)
      even++;
    else
      odd++;
  }

  int overlap = min(even, odd);
  int ans = overlap * 2;

  even -= overlap;
  odd -= overlap;

  if (even > 0) {
    ans++;
  } else {
    ans += (odd / 3) * 2;
    int r = odd % 3;
    if (r == 1)
      ans--;
    else if (r == 2)
      ans++;
  }

  cout << ans << "\n";
  return 0;
}