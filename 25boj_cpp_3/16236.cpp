// 
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
int arr[22][22];
int dist[22][22];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OutOfRange(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pair<int, int> s;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 9) {
        arr[i][j] = 0;
        s = {i, j};
      }
    }
  }

  int sz = 2;
  int ec = 0;
  int ans = 0;

  while (true) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = -1;
      }
    }

    queue<pair<int, int>> que;
    que.emplace(s);
    dist[s.first][s.second] = 0;

    vector<pair<int, int>> cand;
    int mi = -1;

    while (que.size()) {
      int x, y;
      tie(x, y) = que.front();
      que.pop();

      if (arr[x][y] > 0 && arr[x][y] < sz) {
        if (mi == -1 || dist[x][y] <= mi) {
          mi = dist[x][y];
          cand.emplace_back(x, y);
        }
      }

      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OutOfRange(nx, ny)) continue;
        if (dist[nx][ny] != -1) continue;
        if (arr[nx][ny] > sz) continue;
        dist[nx][ny] = dist[x][y] + 1;
        que.emplace(nx, ny);
      }
    }

    if (cand.empty()) break;

    sort(cand.begin(), cand.end());
    s = cand[0];
    arr[s.first][s.second] = 0;
    // cout << s.first << " / " << s.second << " : "  << mi << endl;
    ans += mi;
    ec++;
    if (ec == sz) {
      ec = 0;
      sz++;
    }
  }

  cout << ans << "\n";

  return 0;
}