// 문자열 제곱
// https://www.acmicpc.net/problem/4354

#include <bits/stdc++.h>

using namespace std;

int Solve(const string& s) {
  int n = s.length();
  vector<int> ft;

  ft.push_back(0);
  int i = 1, m = 0;

  while (i + m < n) {
    if (s[i + m] != s[m]) {
      if (m == 0) {
        i++;
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

  m = ft[n - 1];
  int p = n - m;
  if (m % p != 0) return 1;
  int o = n - 2 * p;
  return 2 + o / p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  while (s != ".") {
    cout << Solve(s) << "\n";
    cin >> s;
  }

  return 0;
}