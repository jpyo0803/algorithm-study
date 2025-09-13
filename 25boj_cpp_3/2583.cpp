// 영역 구하기
// https://www.acmicpc.net/problem/2583

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int m, n, k;
bool arr[105][105];
bool vis[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OutOfRange(int x, int y) {
  return x < 0 || x >= m || y < 0 || y >= n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n >> k;

  vector<tuple<int, int, int, int>> bv;
  for (int i = 0; i < k; ++i) {
    int a, b, c, d;
    cin >> b >> a >> d >> c;
    for (int x = a; x < c; ++x) {
      for (int y = b; y < d; ++y) {
        arr[x][y] = true;
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (arr[i][j] || vis[i][j]) continue;
      vis[i][j] = true;

      queue<pair<int, int>> que;
      que.emplace(i, j);

      int cnt = 1;
      while (que.size()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        for (int d = 0; d < 4; ++d) {
          int nx = x + dx[d], ny = y + dy[d];
          if (OutOfRange(nx, ny)) continue;
          if (arr[nx][ny] || vis[nx][ny]) continue;
          vis[nx][ny] = true;
          que.emplace(nx, ny);
          cnt++;  
        }
      }
      ans.push_back(cnt);
    }
  }
  cout << ans.size() << "\n";
  sort(ans.begin(), ans.end());
  for (auto e : ans) cout << e << " ";
  cout << "\n";

  return 0;
}