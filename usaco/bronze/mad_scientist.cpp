// Mad Scientist (Bronze)
// https://www.acmicpc.net/problem/18787

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string a, b;
  cin >> n >> a >> b;

  int ans = 0;
  bool last_diff = false;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      if (last_diff) ans++;
      last_diff = false;
    } else {
      last_diff = true;
    }
  }

  if (last_diff) ans++;
  cout << ans << "\n";

  return 0;
}