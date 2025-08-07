// 연속합 1
// https://www.acmicpc.net/problem/1912

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ans = -1e9;
  int prev = 0;
  for (int i = 0; i < n; ++i) {
    int curr = max(v[i], prev + v[i]);
    ans = max(ans, curr);
    prev = curr;
  }
  cout << ans << "\n";

  return 0;
}