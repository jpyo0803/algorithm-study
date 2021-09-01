// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/

// Binary Search
class Solution {
 public:
  int BinarySearch(const vector<int>& nums, int target, int l, int r) {
    if (l > r) return -1;

    int m = (l + r) / 2;
    if (nums[m] < target) {
      int ret = BinarySearch(nums, target, m + 1, r);
      if (ret == -1) ret = m + 1;
      return ret;
    } else if (nums[m] > target) {
      int ret = BinarySearch(nums, target, l, m - 1);
      if (ret == -1) ret = m;
      return ret;
    } else
      return m;
  }

  int searchInsert(vector<int>& nums, int target) {
    return BinarySearch(nums, target, 0, nums.size() - 1);
  }
};

// lower bound

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    auto it = lower_bound(nums.begin(), nums.end(), target);
    return it - nums.begin();
  }
};