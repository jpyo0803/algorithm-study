// 낚시왕
// https://www.acmicpc.net/problem/17143

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int r, c, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


array<array<int, 105>, 105> tmp, arr;
pair<int, int> sharks[10005]; // s, d

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c >> m;

  for (int i = 0; i < m; ++i) {
    int x, y, s, d, z;
    cin >> x >> y >> s >> d >> z;
    x--, y--, d--;
    
    if (d <= 1) s %= (r - 2) * 2 + 2;
    else s %= (c - 2) * 2 + 2;
    sharks[z] = make_pair(s, d);
    arr[x][y] = z;
  }

  int fp = -1;
  int ans = 0;
  while (fp < c) {
    fp++;

    for (int x = 0; x < r; ++x) {
      if (arr[x][fp] > 0) {
        ans += arr[x][fp];
        arr[x][fp] = 0;
        break;
      }
    }

    tmp = arr;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        arr[i][j] = 0;
      }
    }

    for (int x = 0; x < r; ++x) {
      for (int y = 0; y < c; ++y) {
        if (tmp[x][y] == 0) continue;

        int z = tmp[x][y];
        tmp[x][y] = 0;

        int& s = sharks[z].first;
        int& d = sharks[z].second;

        bool is_vert = d <= 1;

        int cx = x, cy = y;
        for (int i = 0; i < s; ++i) {
          if (is_vert) {
            int nx = cx + dx[d];
            if (nx < 0) nx = 1, d = 1;
            else if (nx >= r) nx = r - 2, d = 0;
            cx = nx;
          } else {
            int ny = cy + dy[d];
            if (ny < 0) ny = 1, d = 2;
            else if (ny >= c) ny = c - 2, d = 3;
            cy = ny;
          }
        }

        if (arr[cx][cy] == 0 || arr[cx][cy] < z) {
          arr[cx][cy] = z;
        }
      }
    }
  }

  cout << ans << "\n";

  return 0;
}