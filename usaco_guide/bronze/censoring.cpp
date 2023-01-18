// Censoring (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=526

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string S, T;
  cin >> S >> T;

  string ans;

  for (auto ch : S) {
    ans.push_back(ch);
    if (ans.length() >= T.length()) {
      if (ans.substr(ans.length() - T.length()) == T) {
        for (int i = 0; i < T.length(); ++i) {
          ans.pop_back();
        }
      }
    }
  }
  cout << ans << "\n";

  return 0;
}