// 뱀
// https://www.acmicpc.net/problem/3190

#include <bits/stdc++.h>

using namespace std;

int n, k, l;

bool a[105][105];
bool vis[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

/*
  E = 0
  W = 1
  S = 2
  N = 3
*/

int Turn(int curr_dir, char turn) {
  if (turn == 'L') {
    if (curr_dir == 0) return 3; // E -> N
    else if (curr_dir == 1) return 2; // W -> S
    else if (curr_dir == 2) return 0; // S -> E
    return 1;
  } else {
    if (curr_dir == 0) return 2; // E -> S
    else if (curr_dir == 1) return 3; // W -> N
    else if (curr_dir == 2) return 1; // S -> W
    return 0;
  }
}

bool OutOfRange(int x, int y) {
  return x < 1 || x > n ||  y < 1 || y > n;
}

void PrintA() {
for (int i = 1; i <= n; ++i) {
  for (int j = 1; j <= n; ++j) {
    cout << (vis[i][j] ? "O" : ".");
  }
  cout << endl;
}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    a[x][y] = true;
  }

  cin >> l;

  int t = 1;
  int dir = 0;

  vis[1][1] = true;
  deque<pair<int, int>> body;
  body.emplace_back(1, 1);

  int i = 1, j = 1;
  bool done = false;

  while (!done) {
    int x = 1e9;
    char c;
    char next_dir = dir;
    if (l-- > 0) {
      cin >> x >> c;
      next_dir = Turn(dir, c);
    }
    // cout << "dir : " << dir << " / " << done << " / " << l << " : " << x << " / " << c << endl;

    while (t <= x) {
      int ni = i + dx[dir], nj = j + dy[dir];
      if (OutOfRange(ni, nj) || vis[ni][nj]) {
        done = true;
        break;
      }
      i = ni, j = nj;

      if (!a[i][j]) {
        vis[body.back().first][body.back().second] = false;
        body.pop_back();
      } else {
        a[i][j] = false;
      }
      body.emplace_front(i, j);
      vis[i][j] = true;

      t++;
    }
    if (done) break;

    dir = next_dir;
  }

  cout << t << endl;

  return 0;
}