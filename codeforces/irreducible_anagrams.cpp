// D. Irreducible Anagrams
// https://codeforces.com/contest/1291/problem/D

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int cnt[200005][26];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  int n = s.length();

  for (int i = 0; i < n; ++i) {
    cnt[i + 1][s[i] - 'a']++;
    for (int j = 0; j < 26; ++j) cnt[i + 1][j] += cnt[i][j];
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    int d = 0;
    for (int i = 0; i < 26; ++i) {
      if (cnt[r][i] - cnt[l - 1][i] > 0) d++;
    }
    
    if (l == r || d > 2) cout << "Yes\n";
    else cout << (s[l - 1] != s[r - 1] ? "Yes" : "No") << "\n";
  }

  return 0;
}