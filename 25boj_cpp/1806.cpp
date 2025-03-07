// 부분합
// https://www.acmicpc.net/problem/1806

#include <bits/stdc++.h>

using namespace std;

int n, s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> s;

  vector<int> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i];

  int ans = 1e9;

  int l, r;
  l = 0;
  r = -1;
  int sum = 0; // sum of [l, r]

  while (true) {
    // if sum < s, increase r
    // else increase l
    if (sum < s) {
      if (r + 1== n) break;
      sum += vv[++r];
    } else {
      sum -= vv[l++];
    }
    if (sum >= s) ans = min(ans, r - l + 1);
  }

  cout << (ans == 1e9 ? 0 : ans) << "\n";

  return 0;
}