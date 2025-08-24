// 퇴사 
// https://www.acmicpc.net/problem/14501

#include <bits/stdc++.h>

using namespace std;

int t[15];
int p[15];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> t[i] >> p[i];

  int ans = 0;
  for (int i = 0; i < (1 << n); ++i) {
    int prev =  -1;
    int cand = 0;
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        if (prev < j && j + t[j] - 1 < n) {
          cand += p[j];
          prev = j + t[j] - 1;
        } else {
          ok = false;
          break;
        }
      }
    }
    if (ok) ans = max(ans, cand);
  }
  cout << ans << "\n";

  return 0;
}