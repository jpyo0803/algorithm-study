// 119. Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> arr(rowIndex + 1);
    for (int r = 0; r <= rowIndex; ++r) {
      arr[r] = vector<int>(r + 1);
    }
    arr[0][0] = 1;
    if (rowIndex >= 1) arr[1][0] = arr[1][1] = 1;

    for (int r = 2; r <= rowIndex; ++r) {
      for (int c = 0; c <= r; ++c) {
        if (c == 0 || c == r)
          arr[r][c] = 1;
        else {
          arr[r][c] = arr[r - 1][c - 1] + arr[r - 1][c];
        }
      }
    }

    return arr[rowIndex];
  }
};