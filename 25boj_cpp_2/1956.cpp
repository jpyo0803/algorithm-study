// 운동
// https://www.acmicpc.net/problem/1956

#include <bits/stdc++.h>

using namespace std;

int v, e;

int adj_mat[405][405]; // '0' means not connected

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> v >> e;

  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj_mat[a][b] = c;
  }

  for (int k = 1; k <= v; ++k) {
    for (int i = 1; i <= v; ++i) {
      if (adj_mat[i][k] == 0) continue;
      for (int j = 1; j <= v; ++j) {
        if (adj_mat[k][j] == 0) continue;
        if (adj_mat[i][j] == 0 || adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j]) {
          adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
        }
      }
    }
  }

  int ans = 2e9;
  for (int i = 1; i <= v; ++i) {
    if (adj_mat[i][i] == 0) continue;
    ans = min(ans, adj_mat[i][i]);
  }

  if (ans == 2e9) cout << "-1\n";
  else cout << ans << "\n";

  return 0;
}