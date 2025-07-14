// C - Black Intervals (ABC)
// https://atcoder.jp/contests/abc411/tasks/abc411_c

#include <bits/stdc++.h>

using namespace std;

int n, q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  vector<int> arr(n, 0);
  int ans = 0;
  while (q--) {
    int x;
    cin >> x;
    x--;
    bool l = false, r = false; // is black
    if (x - 1 >= 0 && arr[x - 1] == 1) l = true;
    if (x + 1 < n && arr[x + 1] == 1) r = true;
    if (arr[x] == 1) {
      arr[x] = 0;
      if (l && r) ans++;
      else if (!l && !r) ans--;
    } else {
      arr[x] = 1;
      if (l && r) ans--;
      else if (!l && !r) ans++;
    }
    cout << ans << "\n";
  }

  return 0;
}