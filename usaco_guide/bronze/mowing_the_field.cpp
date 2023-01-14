// Mowing the Field
// http://www.usaco.org/index.php?page=viewproblem2&cpid=593

#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// FJ's starting point will be 1050, 1050
// 2100 by 2100 is big enough for any direction
// since N = 100, S = 10
int field[2100][2100];  // contains last access time

int N;

int GetDirIdx(char dir) {
  if (dir == 'E')
    return 0;
  else if (dir == 'W')
    return 1;
  else if (dir == 'S')
    return 2;
  return 3;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;

  int ans = -1;

  int curr_x = 1050, curr_y = 1050;
  int t = 1;
  field[curr_x][curr_y] = t;

  for (int i = 0; i < N; ++i) {
    char D;
    int S;
    cin >> D >> S;

    int dir = GetDirIdx(D);
    while (S--) {
      ++t;
      curr_x += dx[dir];
      curr_y += dy[dir];

      // If the next cell had been visited before
      if (field[curr_x][curr_y] != 0) {
        int dt = t - field[curr_x][curr_y];
        if (ans == -1 || dt < ans) {
          ans = dt;
        }
      }
      field[curr_x][curr_y] = t;
    }
  }
  cout << ans << "\n";

  return 0;
}