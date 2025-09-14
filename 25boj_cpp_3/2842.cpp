// 집배원 한상덕 
// https://www.acmicpc.net/problem/2842

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
char arr[55][55];
int E[55][55];
int sx, sy;
int kcnt = 0;

bool vis[55][55];


int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool OOR(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

bool Solve(int lo, int hi) {
  if (E[sx][sy] < lo || hi < E[sx][sy]) return false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      vis[i][j] = false;
    }
  }

  queue<pair<int, int>> que;
  que.emplace(sx, sy);
  vis[sx][sy] = true;

  int kseen = 0;
  while (que.size()) {
    int x, y;
    tie(x, y) = que.front();
    que.pop();

    for (int i = 0; i < 8; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (OOR(nx, ny)) continue;
      if (vis[nx][ny]) continue;
      if (E[nx][ny] < lo || hi < E[nx][ny]) continue;
      vis[nx][ny] = true;
      que.emplace(nx, ny);
      if (arr[nx][ny] == 'K') kseen++;
    }
  }

  return kcnt == kseen;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> av;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 'P') {
        sx = i, sy = j;
        arr[i][j] = '.';
      } else if (arr[i][j] == 'K') {
        kcnt++;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> E[i][j];
      av.push_back(E[i][j]);
    }
  }

  sort(av.begin(), av.end());
  av.erase(unique(av.begin(), av.end()), av.end());
  
  int l = 0, r = 0;
  int ans = 1e9;
  while (r < av.size()) {
    bool res = Solve(av[l], av[r]);
    if (res) {
      ans = min(ans, av[r] - av[l]);
    }

    if (l == r || !res) r++;
    else l++;
  }
  cout << ans << "\n";

  return 0;
}