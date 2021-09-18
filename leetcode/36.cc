// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

// Naive way
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    const int M = board.size();
    const int N = board[0].size();

    bool check[10];
    for (int m = 0; m < M; ++m) {
      for (int i = 0; i < 10; ++i) check[i] = false;
      for (int n = 0; n < N; ++n) {
        char target = board[m][n];
        if (target == '.') continue;
        if (check[target - '0']) return false;
        check[target - '0'] = true;
      }
    }

    for (int n = 0; n < N; ++n) {
      for (int i = 0; i < 10; ++i) check[i] = false;
      for (int m = 0; m < M; ++m) {
        char target = board[m][n];
        if (target == '.') continue;
        if (check[target - '0']) return false;
        check[target - '0'] = true;
      }
    }

    for (int m = 0; m < N; m += 3) {
      for (int n = 0; n < N; n += 3) {
        for (int i = 0; i < 10; ++i) check[i] = false;
        for (int i = m; i < m + 3; ++i) {
          for (int j = n; j < n + 3; ++j) {
            char target = board[i][j];
            if (target == '.') continue;
            if (check[target - '0']) return false;
            check[target - '0'] = true;
          }
        }
      }
    }

    return true;
  }
};

// Using set

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<set<char>> row, col, sqr;
    row = col = sqr = vector<set<char>>(9);

    for (int m = 0; m < 9; ++m) {
      for (int n = 0; n < 9; ++n) {
        char t = board[m][n];
        if (t == '.') continue;
        if (row[m].find(t) != row[m].end()) return false;
        if (col[n].find(t) != col[n].end()) return false;
        if (sqr[(m / 3) * 3 + (n / 3)].find(t) !=
            sqr[(m / 3) * 3 + (n / 3)].end())
          return false;

        row[m].insert(t);
        col[n].insert(t);
        sqr[(m / 3) * 3 + (n / 3)].insert(t);
      }
    }

    return true;
  }
};
