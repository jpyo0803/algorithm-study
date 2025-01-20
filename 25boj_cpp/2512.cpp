// 예산
// https://www.acmicpc.net/problem/2512

#include <bits/stdc++.h>

using namespace std;

int n, budget;

pair<bool, int> valid_check(const vector<int>& vv, int m) {
  int b = budget;
  int max_given = 0;
  for (auto e : vv) {
    if (e < m) { 
      b -= e;
      max_given = max(max_given, e);
    } else {
      b -= m;
      max_given = max(max_given, m);
    } 
  }
  return {b >= 0, max_given}; // if b >= 0, valid
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  /*
    parametric search 문제 같음
  */

  cin >> n;
  vector<int> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i];

  cin >> budget;

  int l = 0;
  int r = budget;

  int ans;

  while (l <= r) {
    int m = (l + r) / 2;
    auto res = valid_check(vv, m);
    if (res.first) {
      l = m + 1;
      ans = res.second;
    } else {
      r = m - 1;
    }
  }

  cout << ans << "\n";

  return 0;
}