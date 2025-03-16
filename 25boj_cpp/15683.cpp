// 감시
// https://www.acmicpc.net/problem/15683

#include <bits/stdc++.h>

using namespace std;

int n, m;
char arr[10][10];
char arr2[10][10]; // copy

vector<pair<int, int>> cctvs;

void CoverWithCam(pair<int, int> pos, int dir) {
  // 0, 1, 2, 3

  int dx, dy;
  dx = dy = 0;
  if (dir == 0) dy = 1;
  else if (dir == 1) dx = 1;
  else if (dir == 2) dy = -1;
  else dx = -1;
  
  int x = pos.first;
  int y = pos.second;

  do {
    if (arr2[x][y] == '0') arr2[x][y] = '#';

    x += dx;
    y += dy;
    if (x < 0 || x >= n || y < 0 || y >= m) break;
    if (arr2[x][y] == '6') break;
  } while (true);
}

int Solve2(vector<int>& dirs) {
  if (dirs.size() == cctvs.size()) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        arr2[i][j] = arr[i][j];
      }
    }
    for (int i = 0; i < cctvs.size(); ++i) {
      int dir = dirs[i]; // 0 = 0, 1 = 90, 2 = 180, 3 = 270
      auto cctv_pos = cctvs[i];
      char cam_type = arr2[cctv_pos.first][cctv_pos.second];

      if (cam_type == '1') {
        CoverWithCam(cctv_pos, dir);
      } else if (cam_type == '2') {
        CoverWithCam(cctv_pos, dir);
        CoverWithCam(cctv_pos, (dir + 2) % 4);
      } else if (cam_type == '3') {
        for (int j = 0; j < 2; ++j) CoverWithCam(cctv_pos, (dir + j) % 4);
      } else if (cam_type == '4') {
        for (int j = 0; j < 3; ++j) CoverWithCam(cctv_pos, (dir + j) % 4);
      } else {
        for (int j = 0; j < 4; ++j) CoverWithCam(cctv_pos, (dir + j) % 4);
      }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (arr2[i][j] == '0') cnt++;
      }
    }
    return cnt;
  }

  int local_ans = 1e9;
  for (int i = 0; i < 4; ++i) {
    dirs.push_back(i);
    local_ans = min(local_ans, Solve2(dirs));
    dirs.pop_back();
  }

  return local_ans;
}

void Solve() {
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] >= '1' && arr[i][j] <= '5') cctvs.emplace_back(i, j);
    }
  }

  vector<int> dirs;
  cout << Solve2(dirs) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solve();

  return 0;
}