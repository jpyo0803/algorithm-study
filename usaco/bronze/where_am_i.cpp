// Where Am I? (Bronze)
// https://www.acmicpc.net/problem/18269

#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> s;

  for (int k = 1; k <= n; ++k) {
    set<string> memo;
    bool ok = true;
    for (int i = 0; i < n - k + 1; ++i) {
      string p = s.substr(i, k);
      if (memo.count(p) > 0) {
        ok = false;
        break;
      }
      memo.insert(p);
    }
    if (ok) {
      cout << k << "\n";
      break;
    }
  }

  return 0;
}