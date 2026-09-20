// BFS-DFS
// https://csacademy.com/contest/archive/task/bfs-dfs

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> bv(n), dv(n);
  for (auto& e : bv) cin >> e;
  for (auto& e : dv) cin >> e;

  if (bv[0] != dv[0] || bv[1] != dv[1]) {
    cout << "-1\n";
    return 0;
  }

  cout << 2 * n - 3 << "\n";
  for (int i = 1; i < n; ++i) {
    cout << 1 << " " << bv[i] << "\n";
  }
  for (int i = 1; i < n - 1; ++i) {
    cout << dv[i] << " " << dv[i + 1] << "\n";
  }

  return 0;
}