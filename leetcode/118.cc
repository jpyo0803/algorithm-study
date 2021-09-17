// 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pt(numRows);
    for (int i = 0; i < numRows; ++i) {
      pt[i] = vector<int>(i + 1);
    }
    pt[0][0] = 1;
    for (int i = 1; i < numRows; ++i) {
      for (int j = 0; j < i + 1; ++j) {
        int a = 0, b = 0;
        if (i - 1 >= 0 && j < i) a = pt[i - 1][j];
        if (i - 1 >= 0 && j - 1 >= 0) b = pt[i - 1][j - 1];
        pt[i][j] = a + b;
      }
    }
    return pt;
  }
};