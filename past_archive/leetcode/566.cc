// 566. Reshape the Matrix
// https://leetcode.com/problems/reshape-the-matrix/

class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if (r * c != mat.size() * mat[0].size()) return mat;
    vector<vector<int>> ans(r, vector<int>(c));
    int rr = 0, cc = 0;
    for (int i = 0; i < mat.size(); ++i) {
      for (int j = 0; j < mat[i].size(); ++j) {
        ans[rr][cc] = mat[i][j];
        ++cc;
        if (cc == c) {
          ++rr;
          cc = 0;
        }
      }
    }
    return ans;
  }
};