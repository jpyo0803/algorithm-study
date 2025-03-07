// 좋다
// https://www.acmicpc.net/problem/1253

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  
  vector<int> vv(n);

  for (int i = 0; i < n; ++i) cin >> vv[i];
  sort(vv.begin(), vv.end());

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    int l = 0;
    int r = n - 1;

    int v = vv[i];

    while (l < r) {
      if (l == i) {
        l++;
        continue;
      }
      if (r == i) {
        r--;
        continue;
      }
      int sum = vv[l] + vv[r];
      if (sum == v) {
        ans++;
        break;
      } else if (sum < v) {
        l++;
      } else if (sum > v) {
        r--;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}