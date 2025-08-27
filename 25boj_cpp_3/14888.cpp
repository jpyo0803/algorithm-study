// 연산자 끼워넣기
// https://www.acmicpc.net/problem/14888

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[12];
int op[4];  // +, -, x, /

pair<int, int> Solve(int x, int d) {
  if (d == n - 1) return {x, x};

  pair<int, int> ret = {2e9, -2e9};
  for (int i = 0; i < 4; ++i) {
    if (op[i] == 0) continue;
    op[i]--;
    int nx = x;
    if (i == 0)
      nx += arr[d + 1];
    else if (i == 1)
      nx -= arr[d + 1];
    else if (i == 2)
      nx *= arr[d + 1];
    else
      nx /= arr[d + 1];
    auto res = Solve(nx, d + 1);
    ret.first = min(ret.first, res.first);
    ret.second = max(ret.second, res.second);
    op[i]++;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 0; i < 4; ++i) cin >> op[i];

  auto ans = Solve(arr[0], 0);
  cout << ans.second << "\n" << ans.first << "\n";

  return 0;
}