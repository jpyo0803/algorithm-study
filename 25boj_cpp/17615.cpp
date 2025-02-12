// 볼모으기
// https://www.acmicpc.net/problem/17615

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  string in;
  cin >> in;

  int ans = 1e9;

  bool blue_on = false;
  bool red_on = false;

  int blue_cnt = 0;
  int red_cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 'R') {
      if (blue_on) red_cnt++;
      red_on = true;
    } else {
      if (red_on) blue_cnt++;
      blue_on = true;
    }
  }
  ans = min(ans, min(red_cnt, blue_cnt));

  blue_on = red_on = false;
  blue_cnt = red_cnt = 0;

  for (int i = n - 1; i >= 0; --i) {
    if (in[i] == 'R') {
      if (blue_on) red_cnt++;
      red_on = true;
    } else {
      if (red_on) blue_cnt++;
      blue_on = true;
    }
  }
  
  ans = min(ans, min(red_cnt, blue_cnt));
  cout << ans << "\n";

  return 0;
}