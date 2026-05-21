// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
 public:
  int FindLowerLimit(const vector<int>& nums, int l, int r, int t) {
    if (l == r) {
      if (nums[l] == t) return l;
      return -1;
    }

    int m = (l + r) / 2;
    if (nums[m] >= t)
      return FindLowerLimit(nums, l, m, t);
    else
      return FindLowerLimit(nums, m + 1, r, t);
  }

  int FindUpperLimit(const vector<int>& nums, int l, int r, int t) {
    if (l == r) {
      if (nums[l] == t) return l;
      return -1;
    }

    int m = (l + r + 1) / 2;
    if (nums[m] <= t)
      return FindUpperLimit(nums, m, r, t);
    else
      return FindUpperLimit(nums, l, m - 1, t);
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    if (len == 0) return vector<int>{-1, -1};
    return vector<int>{FindLowerLimit(nums, 0, len - 1, target),
                       FindUpperLimit(nums, 0, len - 1, target)};
  }
};