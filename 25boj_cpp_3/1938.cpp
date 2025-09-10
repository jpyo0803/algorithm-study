// 통나무 옮기기 
// https://www.acmicpc.net/problem/1938

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
char arr[55][55];
int dist[55][55][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool OutOfRange(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

bool Check(int x, int y, int hori, int dir) {
  if (hori) {
    if (dir <= 1) { // move vert
      int nx = x + dx[dir];
      if (OutOfRange(nx, y)) return false;
      if (arr[nx][y - 1] == '1' || arr[nx][y] == '1' || arr[nx][y + 1] == '1') return false;
    } else {
      int ny = y + dy[dir] * 2;
      if (OutOfRange(x, ny)) return false;
      if (arr[x][ny] == '1') return false;
    }
  } else { // vert
    if (dir <= 1) { // move vert
      int nx = x + dx[dir] * 2;
      if (OutOfRange(nx, y)) return false;
      if (arr[nx][y] == '1') return false;
    } else {
      int ny = y + dy[dir];
      if (OutOfRange(x, ny)) return false;
      if (arr[x - 1][ny] == '1' || arr[x][ny] == '1' || arr[x + 1][ny] == '1') return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  vector<pair<int, int>> namu, dest;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 'B') {
        namu.emplace_back(i, j);
        arr[i][j] = '0';
      } else if (arr[i][j] == 'E') {
        dest.emplace_back(i, j);
        arr[i][j] = '0';
      }
      dist[i][j][0] = dist[i][j][1] = -1;
    }
  }

  int is_namu_hori = namu[0].first == namu[1].first;
  int is_dest_hori = dest[0].first == dest[1].first;

  int namux, namuy, destx, desty;
  if (is_namu_hori) {
    namux = namu[0].first;
    int tmp[3];
    for (int i = 0; i < 3; ++i) tmp[i] = namu[i].second;
    sort(tmp, tmp + 3);
    namuy = tmp[1];
  } else {
    namuy = namu[0].second;
    int tmp[3];
    for (int i = 0; i < 3; ++i) tmp[i] = namu[i].first;
    sort(tmp, tmp + 3);
    namux = tmp[1];
  }
  if (is_dest_hori) {
    destx = dest[0].first;
    int tmp[3];
    for (int i = 0; i < 3; ++i) tmp[i] = dest[i].second;
    sort(tmp, tmp + 3);
    desty = tmp[1];
  } else {
    desty = dest[0].second;
    int tmp[3];
    for (int i = 0; i < 3; ++i) tmp[i] = dest[i].first;
    sort(tmp, tmp + 3);
    destx = tmp[1];
  }

  queue<tuple<int, int, int>> que;
  que.emplace(namux, namuy, is_namu_hori);
  dist[namux][namuy][is_namu_hori] = 0;

  int ans = 0;
  while (que.size()) {
    int x, y, hori;
    tie(x, y, hori) = que.front();
    que.pop();

    // cout << x << " / " << y << " / " << hori << endl;
    if (x == destx && y == desty && hori == is_dest_hori) {
      ans = dist[x][y][hori];
      break;
    }

    for (int i = 0; i < 4; ++i) {
      if (Check(x, y, hori, i) == false) continue;
      int nx = x + dx[i], ny = y + dy[i];
      if (dist[nx][ny][hori] != -1) continue;
      dist[nx][ny][hori] = dist[x][y][hori] + 1;
      que.emplace(nx, ny, hori); 
    }

    bool ok = true;
    for (int i = -1; i <= 1 && ok; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (OutOfRange(x + i, y + j) || arr[x + i][y + j] == '1') {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      if (dist[x][y][1 - hori] == -1) {
        dist[x][y][1 - hori] = dist[x][y][hori] + 1;
        que.emplace(x, y, 1 - hori);
      }
    }
  }
  cout << ans << "\n";

  return 0;
}