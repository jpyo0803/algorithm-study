// 꽃길 
// https://www.acmicpc.net/problem/14620

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

bool vis[12][12];
int g[12][12];

bool OOR(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

bool Check(int i) {
  int x = i / n, y = i % n;
  bool ok = true;
  for (int j = 0; j < 5; ++j) {
    int nx = x + dx[j], ny = y + dy[j];
    if (OOR(nx, ny) || vis[nx][ny]) ok = false;
  }
  return ok;
}

void Mark(int i) {
  int x = i / n, y = i % n;
  for (int j = 0; j < 5; ++j) {
    int nx = x + dx[j], ny = y + dy[j];
    vis[nx][ny] = true;
  }
}

void Unmark(int i) {
  int x = i / n, y = i % n;
  for (int j = 0; j < 5; ++j) {
    int nx = x + dx[j], ny = y + dy[j];
    vis[nx][ny] = false;
  }
}

int GetCost(int i, int j, int k) {
  int ret = 0;
  int x = i / n, y = i % n;
  for (int l = 0; l < 5; ++l) ret += g[x + dx[l]][y + dy[l]];
  x = j / n, y = j % n;
  for (int l = 0; l < 5; ++l) ret += g[x + dx[l]][y + dy[l]];
  x = k / n, y = k % n;
  for (int l = 0; l < 5; ++l) ret += g[x + dx[l]][y + dy[l]];
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  int ans = 1e9;
  for (int i = 0; i < n * n; ++i) {
    if (Check(i)) {
      Mark(i);
      for (int j = i + 1; j < n * n; ++j) {
        if (Check(j)) {
          Mark(j);
          for (int k = j + 1; k < n * n ; ++k) {
            if (Check(k)) {
              ans = min(ans, GetCost(i, j, k));
            }
          }
          Unmark(j);
        }
      }
      Unmark(i);
    }
  }

  cout << ans << "\n";

  return 0;
}