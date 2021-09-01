// 704. Binary Search
// https://leetcode.com/problems/binary-search/

class Solution {
 public:
  int BinarySearch(const vector<int>& nums, int target, int l, int r) {
    if (l > r) return -1;
    int m = (l + r) / 2;
    if (nums[m] > target)
      return BinarySearch(nums, target, l, m - 1);
    else if (nums[m] < target)
      return BinarySearch(nums, target, m + 1, r);
    return m;
  }

  int search(vector<int>& nums, int target) {
    return BinarySearch(nums, target, 0, nums.size() - 1);
  }
};