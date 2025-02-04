// 블로그
// https://www.acmicpc.net/problem/21921

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i];

  int acc = 0;
  int ans = 0;
  int cnt = 0;

  for (int i = 0; i < x - 1; ++i) acc += vv[i];

  for (int i = x - 1; i < n; ++i) {
    if (i > x - 1) {
      acc -= vv[i - x];
    }
    acc += vv[i];
    if (ans < acc) {
      ans = acc;
      cnt = 1;
    } else if (ans == acc) {
      cnt++;
    }
  }

  if (ans == 0) {
    cout << "SAD\n";
  } else {
    cout << ans << "\n" << cnt << "\n";
  }

  return 0;
}