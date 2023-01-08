// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/

// First Try
class Solution {
 public:
  int M_, N_;

  static constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool CheckRange(int r, int c) { return r >= 0 && r < M_ && c >= 0 && c < N_; }

  bool IsEdge(int r, int c) {
    return r == 0 || c == 0 || r == M_ - 1 || c == N_ - 1;
  }

  vector<vector<int>> check_;

  bool FindIfEdge(vector<vector<char>>& board, int r, int c) {
    ++check_[r][c];
    if (IsEdge(r, c)) return true;

    bool res = false;
    for (int k = 0; k < 4; ++k) {
      int nr = r + d[k][0];
      int nc = c + d[k][1];

      if (!CheckRange(nr, nc)) continue;
      if (board[nr][nc] != 'O') continue;
      if (check_[nr][nc] != 0) continue;
      res |= FindIfEdge(board, nr, nc);
    }
    return res;
  }

  void MarkX(vector<vector<char>>& board, int r, int c) {
    ++check_[r][c];
    board[r][c] = 'X';

    for (int k = 0; k < 4; ++k) {
      int nr = r + d[k][0];
      int nc = c + d[k][1];

      if (!CheckRange(nr, nc)) continue;
      if (board[nr][nc] != 'O') continue;
      if (check_[nr][nc] != 1) continue;
      MarkX(board, nr, nc);
    }
  }

  void solve(vector<vector<char>>& board) {
    M_ = board.size();
    N_ = board[0].size();

    check_ = vector<vector<int>>(M_, vector<int>(N_, 0));

    for (int r = 1; r < M_ - 1; ++r) {
      for (int c = 1; c < N_ - 1; ++c) {
        if (board[r][c] != 'O') continue;
        if (check_[r][c] != 0) continue;
        if (!FindIfEdge(board, r, c)) {
          MarkX(board, r, c);
        }
      }
    }
  }
};

// Start from edge
class Solution {
 public:
  int M_, N_;

  static constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool CheckRange(int r, int c) { return r >= 0 && r < M_ && c >= 0 && c < N_; }

  void Dfs(vector<vector<char>>& board, int r, int c) {
    board[r][c] = 'M';

    for (int k = 0; k < 4; ++k) {
      int nr = r + d[k][0];
      int nc = c + d[k][1];

      if (!CheckRange(nr, nc)) continue;
      if (board[nr][nc] != 'O') continue;
      Dfs(board, nr, nc);
    }
  }

  void solve(vector<vector<char>>& board) {
    M_ = board.size();
    N_ = board[0].size();

    for (int r = 0; r < M_; ++r) {
      for (int c = 0; c < N_; ++c) {
        if ((r == 0 || c == 0 || r == M_ - 1 || c == N_ - 1) &&
            (board[r][c] == 'O')) {
          Dfs(board, r, c);
        }
      }
    }

    for (int r = 0; r < M_; ++r) {
      for (int c = 0; c < N_; ++c) {
        if (board[r][c] == 'M') {
          board[r][c] = 'O';
        } else {
          board[r][c] = 'X';
        }
      }
    }
  }
};