// 겹치는 건 싫어
// https://www.acmicpc.net/problem/20922

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  vector<int> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i];

  vector<int> cnt(100010, 0);
  int l, r;

  l = r = 0;

  int ans = 0;

  while (r < n) {
    cnt[vv[r]]++;
    while (cnt[vv[r]] > k) {
      cnt[vv[l++]]--;
    }
    r++;
    ans = max(ans, r - l);
    // cout << l << " / " << r << " : " << ans << endl;
  }

  cout << ans << "\n";

  return 0;
}