// D - Multiple of 2019 (ABC)
// https://atcoder.jp/contests/abc164/tasks/abc164_d

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll cnt[2020];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  
  cnt[0] = 1;

  int suf = 0;
  int f = 1;
  for (int i = s.length() - 1; i >= 0; --i) {
    int d = s[i] - '0';
    suf = (suf + f * d) % 2019;
    cnt[suf]++;
    f = (f * 10) % 2019;
  }

  ll ans = 0;
  for (int i = 0; i < 2019; ++i) {
    ans += cnt[i] * (cnt[i] - 1) / 2;
  }

  cout << ans << "\n";
 
  return 0;
}