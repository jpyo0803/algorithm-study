// 페그 솔리테어
// https://www.acmicpc.net/problem/9207

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OOR(int x, int y) {
  return x < 0 || x >= 5 || y < 0 || y >= 9;
}

pair<int, int> Solve2(vector<vector<char>>& arr, int d) {
  bool last = true;
  int cnt = 0;
  pair<int, int> ret = {1e9, 1e9};
  for (int x = 0; x < 5; ++x) {
    for (int y = 0; y < 9; ++y) {
      if (arr[x][y] != 'o') continue;
      cnt++;
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        int nx2 = x + dx[k] * 2, ny2 = y + dy[k] * 2;
        if (OOR(nx, ny)) continue;
        if (OOR(nx2, ny2)) continue;
        if (arr[nx][ny] == 'o' && arr[nx2][ny2] == '.') {
          arr[x][y] = arr[nx][ny] = '.';
          arr[nx2][ny2] = 'o';
          auto res = Solve2(arr, d + 1);
          if (res < ret) ret = res;
          arr[nx2][ny2] = '.';
          arr[x][y] = arr[nx][ny] = 'o';
          last = false;
        } 
      }
    }
  }

  if (last) return {cnt, d};
  return ret;
}

pair<int, int> Solve() {
  vector<vector<char>> arr(5, vector<char>(9));
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 9; ++j) {
      cin >> arr[i][j];
    }
  }

  return Solve2(arr, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    auto res = Solve();
    cout << res.first << " " << res.second << "\n";
  }

  return 0;
}