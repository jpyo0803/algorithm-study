// 240. Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/

// Do binary search on each row O(M log N)
class Solution {
 public:
  int BinarySearchHorizontal(const vector<int>& arr, int l, int r, int target) {
    if (l > r) return -1;

    int m = (l + r) / 2;
    if (target < arr[m]) {
      return BinarySearchHorizontal(arr, l, m - 1, target);
    } else if (target > arr[m]) {
      return BinarySearchHorizontal(arr, m + 1, r, target);
    } else {
      return m;
    }
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int r = 0; r < matrix.size(); ++r) {
      int c =
          BinarySearchHorizontal(matrix[r], 0, matrix[r].size() - 1, target);
      if (c >= 0) return true;
    }
    return false;
  }
};

// Smarter way O(M + N)
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = 0, c = matrix[0].size() - 1;

    while (c >= 0 && r < matrix.size()) {
      int e = matrix[r][c];
      if (e == target)
        return true;
      else if (target < e)
        --c;
      else
        ++r;
    }
    return false;
  }
};