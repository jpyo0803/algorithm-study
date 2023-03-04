// Where Am I? (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=964

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  string s;
  cin >> s;

  for (int i = 1; i <= N; ++i) {
    set<string> pat;
    bool ok = true;
    for (int j = 0; j < N - i + 1; ++j) {
      string ss = s.substr(j, i);
      if (pat.find(ss) != pat.end()) {
        ok = false;
        break;
      } else {
        pat.insert(ss);
      }
    }
    if (ok) {
      cout << i << "\n";
      break;
    }
  }

  return 0;
}