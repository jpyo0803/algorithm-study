// 플로이드
// https://www.acmicpc.net/problem/11404

#include <bits/stdc++.h>

using namespace std;

int n, m;
int adj_mat[105][105]; // 1 <= value <= 1e5

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (adj_mat[a][b] == 0) adj_mat[a][b] = c;
    else adj_mat[a][b] = min(adj_mat[a][b], c);
  }

  for (int k = 1; k <= n; ++k) {
    for (int u = 1; u <= n; ++u) {
      for (int v = 1; v <= n; ++v) {
        if (u == v) continue;
        if (adj_mat[u][k] && adj_mat[k][v]) {
          if (adj_mat[u][v] == 0 || adj_mat[u][v] > adj_mat[u][k] + adj_mat[k][v]) {
            adj_mat[u][v] = adj_mat[u][k] + adj_mat[k][v];
          }
        }
      }
    }
  }

  for (int u = 1; u <= n; ++u) {
    for (int v = 1; v <= n; ++v) {
      cout << adj_mat[u][v] << " ";
    }
    cout << "\n";
  }

  return 0;
}