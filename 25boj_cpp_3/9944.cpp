// NxM 보드 완주하기
// https://www.acmicpc.net/problem/9944

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;

char arr[32][32];
bool vis[32][32];

int dx[5] = {0, 0, 1, -1, 100};
int dy[5] = {1, -1, 0, 0, 100};

bool OOR(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int ans, cnt;

void Solve(int x, int y, int d, int c, int t) {
  if (ans != -1 && ans <= t) return;
  if (c == cnt) {
    if (ans == -1 || ans > t) {
      ans = t;
    }
    return;
  }
  int nx = x + dx[d], ny = y + dy[d];

  if (OOR(nx, ny) || arr[nx][ny] == '*' || vis[nx][ny]) {
    for (int nd = 0; nd < 4; ++nd) {
      if (nd == d) continue;
      int nx2 = x + dx[nd], ny2 = y + dy[nd];
      if (OOR(nx2, ny2)) continue;
      if (arr[nx2][ny2] == '*') continue;
      if (vis[nx2][ny2]) continue;
      vis[nx2][ny2] = true;
      Solve(nx2, ny2, nd, c + 1, t + 1);
      vis[nx2][ny2] = false;
    }
  } else {
    vis[nx][ny] = true;
    Solve(nx, ny, d, c + 1, t);
    vis[nx][ny] = false;
  } 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int q = 1;
  while (cin >> n >> m) { // 더 이상 읽을 게 없으면 false → 루프 종료
    ans = -1;
    cnt = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> arr[i][j];
        if (arr[i][j] == '.') cnt++;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (arr[i][j] == '*') continue;
        vis[i][j] = true;
        Solve(i, j, 4, 1, 0);
        vis[i][j] = false;
      }
    }

    cout << "Case " << q++ << ": " << ans << "\n";
  }

  return 0;
}