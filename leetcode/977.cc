// 977. Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
 public:
  static int Square(int x) { return x * x; }

  static int Max(int x, int y) { return x < y ? y : x; }

  static int Min(int x, int y) { return x < y ? x : y; }

  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans;

    int zi = 0;
    int min_sqr = 987654321;

    for (int i = 0; i < nums.size(); ++i) {
      int sqr_num = Square(nums[i]);
      if (sqr_num < min_sqr) {
        min_sqr = sqr_num;
        zi = i;
      }
    }

    ans.push_back(min_sqr);
    int i = zi - 1;
    int j = zi + 1;

    while (i >= 0 || j < nums.size()) {
      int l = -1, r = -1;
      if (i >= 0) l = Square(nums[i]);
      if (j < nums.size()) r = Square(nums[j]);

      if (l != -1 && r != -1) {
        if (l < r) {
          ans.push_back(l);
          --i;
        } else if (l > r) {
          ans.push_back(r);
          ++j;
        } else {
          ans.push_back(l);
          ans.push_back(r);
          --i;
          ++j;
        }
      } else if (l != -1) {
        ans.push_back(l);
        --i;
      } else if (r != -1) {
        ans.push_back(r);
        ++j;
      }
    }

    return ans;
  }
};