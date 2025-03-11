// 여행 가자
// https://www.acmicpc.net/problem/1976

#include <bits/stdc++.h>

using namespace std;

int n, m;

bool adj_mat[205][205];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      bool conn;
      cin >> conn;
      if (i == j) assert(conn == false); // hope no self edge
      adj_mat[i][j] = adj_mat[j][i] = conn;
    }
  }

  for (int i = 0; i < n; ++i) adj_mat[i][i] = true;

  // Only require connectivity between vertices based on FW alg.
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        bool conn = adj_mat[j][i] && adj_mat[i][k];
        adj_mat[j][k] |= conn; 
        adj_mat[k][j] |= conn;
      }
    }
  }

  vector<int> path(m);
  for (int i = 0; i < m; ++i) {
    cin >> path[i];
    path[i]--;
  }

  bool ok = true;
  for (int i = 0; i < m - 1; ++i) {
    ok &= adj_mat[path[i]][path[i + 1]];
    if (ok == false) break;
  }

  cout << (ok ? "YES" : "NO") << "\n";

  return 0;
}