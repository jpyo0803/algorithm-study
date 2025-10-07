// Painting the Barn (Silver)
// https://www.acmicpc.net/problem/17037

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, k;
int arr[1005][1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    arr[x1][y1]++, arr[x1][y2]--, arr[x2][y1]--, arr[x2][y2]++;
  }

  int ans = 0;
  for (int i = 0; i <= 1e3; ++i) {
    for (int j = 0; j <= 1e3; ++j) {
      int a = i - 1 >= 0 ? arr[i - 1][j] : 0;
      int b = j - 1 >= 0 ? arr[i][j - 1] : 0;
      int c = i - 1 >= 0 && j - 1 >= 0 ? arr[i - 1][j - 1] : 0;
      arr[i][j] += a + b - c;
      if (arr[i][j] == k) ans++;
    }
  }
  cout << ans << "\n";

  return 0;
}