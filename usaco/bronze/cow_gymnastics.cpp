// Cow Gymnastics (Bronze)
// https://www.acmicpc.net/problem/18268

#include <bits/stdc++.h>

using namespace std;

int k, n;
int order[10][20];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> k >> n;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      x--;
      order[i][x] = j;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      bool ok = true;
      for (int a = 0; a < k; ++a) {
        if (order[a][i] < order[a][j]) ok = false;
      }
      if (ok) ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}