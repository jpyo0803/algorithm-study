// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
 public:
  int SearchRow(const vector<vector<int>>& matrix, int l, int r, int t) {
    if (l > r) return -1;

    int m = (l + r) / 2;
    if (matrix[m][0] <= t && matrix[m].back() >= t) {
      return m;
    } else if (matrix[m].back() < t) {
      return SearchRow(matrix, m + 1, r, t);
    } else if (matrix[m][0] > t) {
      return SearchRow(matrix, l, m - 1, t);
    }
    return -1;
  }

  int SearchCol(const vector<vector<int>>& matrix, int row, int l, int r,
                int t) {
    if (l > r) return -1;

    int m = (l + r) / 2;
    if (matrix[row][m] < t) {
      return SearchCol(matrix, row, m + 1, r, t);
    } else if (matrix[row][m] > t) {
      return SearchCol(matrix, row, l, m - 1, t);
    } else {
      return m;
    }
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    int r = SearchRow(matrix, 0, m - 1, target);
    if (r == -1) return false;
    int ans = SearchCol(matrix, r, 0, n - 1, target);
    return (ans == -1 ? false : true);
  }
};