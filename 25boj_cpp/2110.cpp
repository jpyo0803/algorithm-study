// 공유기 설치
// https://www.acmicpc.net/problem/2110

#include <bits/stdc++.h>

using namespace std;

int n, c;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> c;
  vector<int> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i];

  sort(vv.begin(), vv.end());
  // 1 2 4 8 9

  int l, r;
  l = 0;
  r = 2e9;

  long long ans = 0;

  while (l <= r) {
    long long mid = ((long long)l + r) / 2; // long long cuz 1e9 + 2e9 overflows
    
    int cnt = 0;
    int last_pos = -1;
    for (auto e : vv) {
      if (last_pos == -1) {
        cnt++;
        last_pos = e;
      } else {
        if (e - last_pos >= mid) {
          last_pos = e;
          cnt++;
        }
      }
    }
    // cout << mid << " / " << cnt << endl;
    if (cnt >= c) {
      ans = max(ans, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << ans << "\n";

  return 0;
}