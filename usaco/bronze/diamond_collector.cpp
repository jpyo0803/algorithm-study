// Diamond Collector (Bronze)
// https://www.acmicpc.net/problem/12005

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int low = v[i];
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (low <= v[j] && v[j] <= low + k) cnt++;
    }
    ans = max(ans, cnt);
  }

  cout << ans << "\n";

  return 0;
}