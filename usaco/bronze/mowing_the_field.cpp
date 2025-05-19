// Mowing the Field (Bronze)
// https://www.acmicpc.net/problem/11978

#include <bits/stdc++.h>

using namespace std;

int n;

int field[3000][3000];
int visited[3000][3000];

int x = 1500, y = 1500, t = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 3000; ++i) {
    for (int j = 0; j < 3000; ++j) {
      visited[i][j] = -1;
    }
  }

  cin >> n;

  visited[x][y] = 0;

  int ans = 1e9;
  for (int i = 0; i < n; ++i) {
    char dir;
    int s;
    cin >> dir >> s;

    while (s--) {
      t++;
      if (dir == 'E') {
        y++;
      } else if (dir == 'W') {
        y--;
      } else if (dir == 'S') {
        x++;
      } else {
        x--;
      }
      
      if (visited[x][y] != -1) {
        ans = min(ans, t - visited[x][y]);
      }
      visited[x][y] = t;
    }

  }

  cout << (ans == 1e9 ? -1 : ans) << "\n";

  return 0;
}