// Distinct Numbers
// https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  sort(arr.begin(), arr.end());

  int ans = 0;
  int x = 0;
  for (auto e : arr) {
    if (x != e) {
      ans++;
      x = e;
    }
  }

  cout << ans << "\n";

  return 0;
}