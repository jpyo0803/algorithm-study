// G. ABBC or BACB
// https://codeforces.com/problemset/problem/1873/G

#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int mi = 1e9;

    int b = 0, a = 0;
    int ans = 0;
    int cnt = 0;
    for (auto ch : s) {
      if (ch == 'B') {
        b++;
        mi = min(mi, cnt);
        if (cnt > 0) a++;
        ans += cnt;
        cnt = 0;
      } else {
        cnt++;
      }
    }
    if (cnt > 0) {
      a++;
      mi = min(mi, cnt);
    }
    ans += cnt;

    if (a > b && mi != 1e9) ans -= mi;
    if (b == 0) ans = 0;
    cout << ans << "\n";
  }

  return 0;
}