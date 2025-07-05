// B - Precondition (ABC)
// https://atcoder.jp/contests/abc412/tasks/abc412_b

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s, t;
  cin >> s >> t;

  bool exist[256]{};
  for (auto ch : t) exist[ch] = true;

  bool ok = true;
  for (int i = 1; i < s.length(); ++i) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      if (exist[s[i - 1]] == false) {
        ok = false;
        break;
      }
    }
  }

  cout << (ok ? "Yes" : "No") << "\n";
  
  return 0;
}