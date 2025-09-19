// 열쇠 
// https://www.acmicpc.net/problem/9328

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int h, w;
char arr[105][105];
bool vis[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OOR(int x, int y) {
  return x < 0 || x > h + 1 || y < 0 || y > w + 1;
}

int Solve() {
  cin >> h >> w;  
  for (int i = 0; i <= h + 1; ++i) {
    for (int j = 0; j <= w + 1; ++j) {
      arr[i][j] = '.';
    }
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      cin >> arr[i][j];
    }
  }

  string s;
  cin >> s;
  
  int key = 0;
  if (s[0] != '0') {
    for (auto ch : s) {
      key |= (1 << (ch - 'a'));
    }
  }

  int ans = 0;
  while (true) {
    // find keys until no more is found
    for (int i = 0; i <= h + 1; ++i) {
      for (int j = 0; j <= w + 1; ++j) {
        vis[i][j] = false;
      }
    }

    int next_key = key;

    queue<pair<int, int>> que;
    que.emplace(0, 0);
    vis[0][0] = true;

    bool found = false;
    while (que.size()) {
      int x, y;
      tie(x, y) = que.front();
      que.pop();

      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOR(nx, ny)) continue;
        if (arr[nx][ny] == '*') continue;
        if ('A' <= arr[nx][ny] && arr[nx][ny] <= 'Z') {
          if ((key & (1 << (arr[nx][ny] - 'A'))) == 0) {
            continue;
          }
        }
        if (vis[nx][ny]) continue;
        vis[nx][ny] = true;
        que.emplace(nx, ny);
        if ('a' <= arr[nx][ny] && arr[nx][ny] <= 'z') {
          next_key |= (1 << (arr[nx][ny] - 'a'));
          arr[nx][ny] = '.';
        }
        if (arr[nx][ny] == '$') {
          ans++;
          arr[nx][ny] = '.';
        }
      }
    }

    if (key == next_key) break;
    key = next_key;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  
  while (t--) {
    cout << Solve() << "\n";
  }

  return 0;
}