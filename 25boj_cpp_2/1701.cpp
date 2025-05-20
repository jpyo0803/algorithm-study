// Cubeditor
// https://www.acmicpc.net/problem/1701

#include <bits/stdc++.h>

using namespace std;

int Solve(string s) {
  int ret = 0;
  // return the max match count during the failure table construction
  int n = s.length();
  vector<int> ft;
  ft.push_back(0);
  int i = 1;
  int m = 0;
  while (i + m < n) {
    if (s[i + m] != s[m]) {
      if (m == 0) {
        ++i;
        ft.push_back(0);
      } else {
        int L = ft[m - 1];
        i += m - L;
        m = L;
      }
    } else {
      m++;
      ft.push_back(m);
      if (m == n) {
        int L = ft[m - 1];
        i += m - L;
        m = L;
      }
    }
  }
  for (auto e : ft) ret = max(ret, e);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  int ans = 0;

  int n = s.length();
  for (int i = 0; i < n; ++i) {
    ans = max(ans, Solve(s.substr(i, n - i)));
  }
  cout << ans << "\n";

  return 0;
}