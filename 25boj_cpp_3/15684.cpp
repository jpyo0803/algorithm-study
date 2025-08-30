// 사다리 조작
// https://www.acmicpc.net/problem/15684

#include <bits/stdc++.h>

using namespace std;

int n, m, h;

bool adj[32][12][2]; // left, right

bool Eval() {
  for (int y = 0; y < n; ++y) {
    int pos = y;
    for (int x = 0; x < h; ++x) {
      if (adj[x][pos][0]) pos--;
      else if (adj[x][pos][1]) pos++;
    }
    if (pos != y) return false;
  }
  return true;
}

int ans = -1;
void Solve(int d) {
  if (ans != -1 && d >= ans) return;
  if (Eval()) {
    if (ans == -1 || ans > d) ans = d;
  }
  if (d == 3) return;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < h; ++x) {
      if (adj[x][y][0] || adj[x][y][1] || adj[x][y + 1][1]) continue;
      adj[x][y][1] = adj[x][y + 1][0] = true;
      Solve(d + 1);
      adj[x][y][1] = adj[x][y + 1][0] = false;
      // skip redundants that produce same results
      while (x < h && !adj[x][y][0] && !adj[x][y][1] && !adj[x][y + 1][1]) ++x;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> h;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a][b][1] = adj[a][b + 1][0] = true;
  }

  Solve(0);

  cout << ans << "\n";

  return 0;
}