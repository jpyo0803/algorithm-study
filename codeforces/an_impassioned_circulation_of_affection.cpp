// An impassioned circulation of affection
// https://codeforces.com/problemset/problem/814/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, q;
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> s;
  cin >> q;

  while (q--) {
    int m;
    char c;
    cin >> m >> c;
    
    int l = 0, r = 0;
    int ans = 0;
    while (r < n) {
      while (r < n) {
        if (s[r] != c) {
          if (m > 0) m--;
          else break;
        }
        r++;
      }

      ans = max(ans, r - l);
      if (s[l++] != c) m++;
    }
    cout << ans << "\n";
  }

  return 0;
}