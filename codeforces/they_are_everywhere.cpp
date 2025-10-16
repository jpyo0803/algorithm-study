// They Are Everywhere
// https://codeforces.com/problemset/problem/701/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int chk[256];
bool seen[256];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  
  int cnt = 0;
  for (auto ch : s) {
    if (seen[ch] == false) {
      cnt++;
      seen[ch] = true;
    }
  }

  int l = 0, r = -1;
  int cnt2 = 0;

  int ans = 1e9;
  while (r < n) {
    if (cnt2 < cnt) {
      if (r + 1 == n) break;
      if (chk[s[r + 1]] == 0) cnt2++;
      chk[s[r + 1]]++;
      r++;
      // cout << r << " : " << cnt2 << endl;
    } else {
      if (l == n) break;
      if (chk[s[l]] == 1) cnt2--;
      chk[s[l]]--;
      l++;
    }
    if (cnt2 == cnt) ans = min(ans, r - l + 1);
  }
  cout << ans << "\n";

  return 0;
}