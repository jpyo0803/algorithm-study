// 79. Word Search
// https://leetcode.com/problems/word-search/

class Solution {
 public:
  int M_, N_;

  vector<vector<bool>> check_;

  static constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool CheckRange(int r, int c) { return r >= 0 && r < M_ && c >= 0 && c < N_; }

  bool ans_;

  void Solve(const vector<vector<char>>& board, int r, int c,
             const string& word, int nth) {
    if (ans_) return;
    if (board[r][c] != word[nth]) return;
    if (word.length() - 1 == nth) {
      ans_ = true;
      return;
    }

    for (int i = 0; i < 4; ++i) {
      int nr = r + d[i][0];
      int nc = c + d[i][1];
      if (!CheckRange(nr, nc)) continue;
      if (check_[nr][nc]) continue;
      check_[nr][nc] = true;
      Solve(board, nr, nc, word, nth + 1);
      check_[nr][nc] = false;
    }
  }

  bool exist(vector<vector<char>>& board, string word) {
    M_ = board.size();
    N_ = board[0].size();
    ans_ = false;

    check_ = vector<vector<bool>>(M_, vector<bool>(N_, false));
    for (int r = 0; r < M_; ++r) {
      for (int c = 0; c < N_; ++c) {
        if (check_[r][c]) continue;
        check_[r][c] = true;
        Solve(board, r, c, word, 0);
        if (ans_) break;
        check_[r][c] = false;
      }
    }
    return ans_;
  }
};