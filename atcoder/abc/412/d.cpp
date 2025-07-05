// D - Make 2-Regular Graph (ABC)
// https://atcoder.jp/contests/abc412/tasks/abc412_d

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  vector<vector<bool>> conn(n, vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a > b) swap(a, b);
    conn[a][b] = true;
  }

  int ans = 1e9;

  vector<int> perm;
  for (int i = 0; i < n; ++i) perm.push_back(i);
  do {
    vector<vector<bool>> g(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
      int u = perm[i], v = perm[(i + 1) % n];
      if (u > v) swap(u, v);
      g[u][v] = true;
    }
    int cand = 0;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (conn[i][j] != g[i][j]) cand++;
      }
    }
    ans = min(ans, cand);

    for (int k = 3; k <= n - 3; ++k) {
      vector<vector<bool>> g2(n, vector<bool>(n, false));
      for (int i = 0; i < k; ++i) {
        int u = perm[i], v = perm[(i + 1) % k];
        if (u > v) swap(u, v);
        g2[u][v] = true;
      }
      for (int i = 0; i < n - k; ++i) {
        int u = perm[i + k], v = perm[((i + 1) % (n - k)) + k];
        if (u > v) swap(u, v);
        g2[u][v] = true;
      }
      int cand = 0;
      for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (conn[i][j] != g2[i][j]) cand++;
        }
      }
      ans = min(ans, cand);
    }
  } while (next_permutation(perm.begin(), perm.end()));

  cout << ans << "\n";

  return 0;
}