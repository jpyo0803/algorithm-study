// 성곽 
// https://www.acmicpc.net/problem/2234

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int m, n;
int arr[55][55];
bool vis[55][55];
int grp[55][55];
int cnt[2505];

bool IsWall(int x, int pos) {
  return (x >> pos) & 0b1;
}

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool OutOfRange(int x, int y) {
  return x < 0 || x >= m || y < 0 || y >= n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }

  int num = 0;
  int ans = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (vis[i][j]) continue;
      vis[i][j] = true;
      num++;

      vector<pair<int, int>> v;
      queue<pair<int, int>> que;
      que.emplace(i, j);

      grp[i][j] = num;
      cnt[num] = 1;

      while (que.size()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();
        
        for (int k = 0; k < 4; ++k) {
          if (IsWall(arr[x][y], k)) continue;
          int nx = x + dx[k], ny = y + dy[k];
          if (OutOfRange(nx, ny)) continue;
          if (vis[nx][ny]) continue;
          vis[nx][ny] = true;
          grp[nx][ny] = num;
          que.emplace(nx, ny);
          cnt[num]++;
        } 
      }
      ans = max(ans, cnt[num]);
    }
  }

  cout << num << "\n";
  cout << ans << "\n";

  int ans2 = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + 1 < m && grp[i][j] != grp[i + 1][j]) {
        ans = max(ans, cnt[grp[i][j]] + cnt[grp[i + 1][j]]);
      }
      if (j + 1 < n && grp[i][j] != grp[i][j + 1]) {
        ans = max(ans, cnt[grp[i][j]] + cnt[grp[i][j + 1]]);
      }
    }
  }
  cout << ans << "\n";

  return 0;
}