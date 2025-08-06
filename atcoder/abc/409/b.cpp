// B - Citation (ABC)
// https://atcoder.jp/contests/abc409/tasks/abc409_b

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (arr[j] >= arr[i]) cnt++;
    }
    int cand = min(cnt, arr[i]);
    ans = max(ans, cand);
  }

  cout << ans << "\n";

  return 0;
}