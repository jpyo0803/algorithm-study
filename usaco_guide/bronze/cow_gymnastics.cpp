// Cow Gymnastics
// http://www.usaco.org/index.php?page=viewproblem2&cpid=963

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int K, N;
  cin >> K >> N;
  vector<vector<int>> v(K, vector<int>(N));

  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < N; ++j) {
      int a;
      cin >> a;
      v[i][a - 1] = j;
    }
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      bool ok = true;
      for (int k = 0; k < K; ++k) {
        if (v[k][i] <= v[k][j]) {
          ok = false;
          break;
        }
      }
      if (ok) ++ans;
    }
  }

  cout << ans << "\n";

  return 0;
}