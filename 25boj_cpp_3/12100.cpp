// 2048 (Easy)
// https://www.acmicpc.net/problem/12100

#include <bits/stdc++.h>

using namespace std;

int n;
bool merged[20][20];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void ResetMerged() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      merged[i][j] = false;
    }
  }
}

bool OutOfRange(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void Move2(vector<vector<int>>& board, int x, int y, int dx, int dy) {
  int cx = x, cy = y;
  while (!OutOfRange(cx + dx, cy + dy) && board[cx + dx][cy + dy] == 0) {
    cx += dx;
    cy += dy;
  }
  int nx = cx + dx;
  int ny = cy + dy;
  if (!OutOfRange(nx, ny) && board[x][y] == board[nx][ny] &&
      merged[nx][ny] == false) {
    merged[nx][ny] = true;
    board[nx][ny] = board[x][y] * 2;
    board[x][y] = 0;
  } else {
    swap(board[x][y], board[cx][cy]);
  }
}

void Move(vector<vector<int>>& board, int dir) {
  ResetMerged();

  if (dir == 0) {  // east
    for (int i = 0; i < n; ++i) {
      for (int j = n - 1; j >= 0; --j) {
        if (board[i][j] == 0) continue;
        Move2(board, i, j, dx[dir], dy[dir]);
      }
    }
  } else if (dir == 1) {  // west
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 0) continue;
        Move2(board, i, j, dx[dir], dy[dir]);
      }
    }
  } else if (dir == 2) {  // south
    for (int j = 0; j < n; ++j) {
      for (int i = n - 1; i >= 0; --i) {
        if (board[i][j] == 0) continue;
        Move2(board, i, j, dx[dir], dy[dir]);
      }
    }
  } else {  // north
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < n; ++i) {
        if (board[i][j] == 0) continue;
        Move2(board, i, j, dx[dir], dy[dir]);
      }
    }
  }
}

int Solve(vector<vector<int>> board, int d, int dir) {
  if (d == 5) {
    int ma = board[0][0];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ma = max(ma, board[i][j]);
      }
    }
    return ma;
  }

  Move(board, dir);

  int ret = 0;
  for (int i = 0; i < 4; ++i) {
    ret = max(ret, Solve(board, d + 1, i));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<vector<int>> board(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    ans = max(ans, Solve(board, 0, i));
  }
  cout << ans << "\n";

  return 0;
}