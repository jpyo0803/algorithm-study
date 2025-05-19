// Censoring (Bronze)
// https://www.acmicpc.net/problem/10750

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string t, p;
  cin >> t >> p;

  string ans;
  const int p_len = p.length();
  for (auto ch : t) {
    ans.push_back(ch);

    if (ans.size() >= p_len) {
      if (ans.substr(ans.length() - p_len, p_len) == p) {
        for (int i = 0; i < p_len; ++i) ans.pop_back();
      }
    }
  }

  cout << ans << "\n";

  return 0;
}