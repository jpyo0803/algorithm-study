// C - Not All Covered (ABC)
// https://atcoder.jp/contests/abc408/tasks/abc408_c

#include <bits/stdc++.h>

using namespace std;

int n, m;
int da[1000005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    da[l]++;
    da[r + 1]--;
  }

  int ans = 1e9;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += da[i];
    ans = min(ans, cnt);
  }

  cout << ans << "\n";

  return 0;
}