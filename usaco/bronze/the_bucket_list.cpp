// The Bucket List (Bronze)
// https://www.acmicpc.net/problem/16770

#include <bits/stdc++.h>

using namespace std;

int n;

int arr[1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int s, t, b;
    cin >> s >> t >> b;
    for (int j = s; j <= t; ++j) arr[j] += b;
  }

  int ans = 0;
  for (int i = 1; i <= 1000; ++i) ans = max(ans, arr[i]);
  cout << ans << "\n";

  return 0;
}