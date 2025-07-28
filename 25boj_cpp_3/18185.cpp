// 라면 사기 (Small)
// https://www.acmicpc.net/problem/18185

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    if (i + 2 < n && arr[i] > 0 && arr[i + 1] > arr[i + 2]) {
      int v = min({arr[i], arr[i + 1], arr[i + 1] - arr[i + 2]});
      arr[i] -= v;
      arr[i + 1] -= v;
      ans += v * 5;
    }

    if (i + 2 < n) {
      int v = min({arr[i], arr[i + 1], arr[i + 2]});
      arr[i] -= v;
      arr[i + 1] -= v;
      arr[i + 2] -= v;
      ans += v * 7;
    }
    if (i + 1 < n) {
      int v = min(arr[i], arr[i + 1]);
      arr[i] -= v;
      arr[i + 1] -= v;
      ans += v * 5;
    }
    ans += 3 * arr[i];
    arr[i] = 0;
  }

  cout << ans << "\n";

  return 0;
}