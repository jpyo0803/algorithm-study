// 회전 초밥
// https://www.acmicpc.net/problem/2531

#include <bits/stdc++.h>

using namespace std;

int n, d, k, c;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> d >> k >> c;
  
  vector<int> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i];
  for (int i = 0; i < k - 1; ++i) vv.push_back(vv[i]);

  vector<int> cnt(d + 10, 0);
  int diff_types = 0;

  int ans = 0;
  for (int i = 0; i < vv.size(); ++i) {
    int e2a = vv[i];
    cnt[e2a]++;
    if (cnt[e2a] == 1) diff_types++;

    if (i >= k) {
      int e2r = vv[i - k];
      cnt[e2r]--;
      if (cnt[e2r] == 0) diff_types--; 
    }

    ans = max(ans, diff_types + (cnt[c] == 0));
  }

  cout << ans << "\n";

  return 0;
}