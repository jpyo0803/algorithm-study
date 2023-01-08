// 542. 01 Matrix
// https://leetcode.com/problems/01-matrix/

// Left-Top and Right-Bottom 2 pass approach
class Solution {
 public:
  static constexpr int kInf = 987654321;
  static constexpr int d[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

  int M_, N_;

  bool CheckRange(int r, int c) { return r >= 0 && r < M_ && c >= 0 && c < N_; }

  static int Min(int x, int y) { return x < y ? x : y; }

  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    M_ = mat.size();
    N_ = mat[0].size();

    vector<vector<int>> cache(M_, vector<int>(N_, kInf));

    for (int i = 0; i < M_; ++i) {
      for (int j = 0; j < N_; ++j) {
        if (mat[i][j] == 0) {
          cache[i][j] = 0;
        } else {
          for (int k = 0; k < 2; ++k) {
            int ni = i + d[k][0];
            int nj = j + d[k][1];
            if (!CheckRange(ni, nj)) continue;
            cache[i][j] = Min(cache[i][j], cache[ni][nj] + 1);
          }
        }
      }
    }

    for (int i = M_ - 1; i >= 0; --i) {
      for (int j = N_ - 1; j >= 0; --j) {
        if (mat[i][j] == 0) {
          cache[i][j] = 0;
        } else {
          for (int k = 2; k < 4; ++k) {
            int ni = i + d[k][0];
            int nj = j + d[k][1];
            if (!CheckRange(ni, nj)) continue;
            cache[i][j] = Min(cache[i][j], cache[ni][nj] + 1);
          }
        }
      }
    }

    return cache;
  }
};