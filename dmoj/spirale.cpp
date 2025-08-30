// Spirale
// https://dmoj.ca/problem/coci17c5p2

#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int arr[55][55];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool OutOfRange(int x, int y) {
  return x < 1 || x > n || y < 1 || y > m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;

  while (k--) {
    int x, y, z;
    cin >> x >> y >> z;

    int t = 1;
    int s = 1; // stride
    int dir = 0;
    int c = 0;

    while (c < n * m) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < s; ++j) {
          if (!OutOfRange(x, y)) {
            if (arr[x][y] == 0 || arr[x][y] > t) arr[x][y] = t;
            c++;
          }
          x += dx[dir], y += dy[dir];
          t++;
        }
        if (z == 1) dir = (dir - 1 + 4) % 4;
        else dir = (dir + 1) % 4;
      }
      s++;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}