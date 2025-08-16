// 구슬 탈출 2
// https://www.acmicpc.net/problem/13460

#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> Move(const vector<vector<char>>& board, pair<int, int> pos,
                    int dir) {
  int x = pos.first, y = pos.second;
  while (true) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    char p = board[nx][ny];
    if (p == '#' || p == 'R' || p == 'B') break;
    x = nx, y = ny;
    if (p == 'O') break;
  }
  return {x, y};
}

bool IsRedFirst(const vector<vector<char>>& board, pair<int, int> r,
                pair<int, int> b, int dir) {
  if (dir == 0)
    return r.second > b.second;
  else if (dir == 1)
    return r.second < b.second;
  else if (dir == 2)
    return r.first > b.first;
  return r.first < b.first;
}

int ans = -1;
void Solve(vector<vector<char>>& board, pair<int, int> r, pair<int, int> b,
           int dir, int depth) {
  if (ans != -1 && ans <= depth) return;
  if (depth > 10) return;
  bool ok = false;

  bool r_first = IsRedFirst(board, r, b, dir);

  pair<int, int> nr, nb;
  if (r_first) {
    nr = Move(board, r, dir);
    if (nr != r) {
      if (board[nr.first][nr.second] != 'O') board[nr.first][nr.second] = 'R';
      board[r.first][r.second] = '.';
    }
    nb = Move(board, b, dir);
    if (nb != b) {
      if (board[nb.first][nb.second] != 'O') board[nb.first][nb.second] = 'B';
      board[b.first][b.second] = '.';
    }
  } else {
    nb = Move(board, b, dir);
    if (nb != b) {
      if (board[nb.first][nb.second] != 'O') board[nb.first][nb.second] = 'B';
      board[b.first][b.second] = '.';
    }
    nr = Move(board, r, dir);
    if (nr != r) {
      if (board[nr.first][nr.second] != 'O') board[nr.first][nr.second] = 'R';
      board[r.first][r.second] = '.';
    }
  }

  bool r_in = board[nr.first][nr.second] == 'O';
  bool b_in = board[nb.first][nb.second] == 'O';

  if (!b_in && !r_in) {
    for (int i = 0; i < 4; ++i) {
      Solve(board, nr, nb, i, depth + 1);
    }
  } else {
    if (r_in && !b_in) {
      if (ans == -1 || ans > depth) {
        ans = depth;
      }
    }
  }

  if (nr != r) {
    if (board[nr.first][nr.second] == 'R') board[nr.first][nr.second] = '.';
    board[r.first][r.second] = 'R';
  }
  if (nb != b) {
    if (board[nb.first][nb.second] == 'B') board[nb.first][nb.second] = '.';
    board[b.first][b.second] = 'B';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  pair<int, int> r, b;
  vector<vector<char>> board(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 'R') {
        r.first = i, r.second = j;
      }
      if (board[i][j] == 'B') {
        b.first = i, b.second = j;
      }
    }
  }

  for (int i = 0; i < 4; ++i) {
    Solve(board, r, b, i, 1);
  }

  cout << ans << "\n";

  return 0;
}