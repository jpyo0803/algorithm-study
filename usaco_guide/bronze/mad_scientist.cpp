// Mad Scientist
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1012

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  string a, b;
  cin >> a >> b;

  int ans = 0;

  bool ok = false;
  for (int i = 0; i < N; ++i) {
    if (a[i] != b[i]) {
      if (ok == false) {
        ok = true;
      }
    } else {
      if (ok == true) {
        ok = false;
        ans++;
      }
    }
  }

  if (ok == true) ans++;

  cout << ans << "\n";

  return 0;
}