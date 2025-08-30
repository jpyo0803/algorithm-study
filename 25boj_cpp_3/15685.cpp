// 드래곤 커브
// https://www.acmicpc.net/problem/15685

#include <bits/stdc++.h>

using namespace std;

bool vis[105][105];

int n;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  while (n--) {
    int x, y, d, g;
    cin >> y >> x >> d >> g;

    // d = 0, E (N)
    // d = 1, N (W)
    // d = 2, W (S)
    // d = 3, S (E)
    vector<int> trace = {d};
    while (g--) {
      for (int i = trace.size() - 1; i >= 0; --i) trace.push_back((trace[i] + 1) % 4);
    }
    vis[x][y] = true;
    for (auto e : trace) {
      x += dx[e], y += dy[e];
      vis[x][y] = true;
    }
  }

  int ans = 0;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (vis[i][j] && vis[i + 1][j] && vis[i][j + 1] && vis[i + 1][j + 1]) ans++;
    }
  }
  cout << ans << "\n";

  return 0;
}