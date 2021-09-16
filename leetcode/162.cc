// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/

class Solution {
 public:
  int Solve(const vector<int>& nums, int l, int r) {
    if (l > r) return r;
    int m = (l + r) / 2;
    if ((m - 1 == -1 || nums[m - 1] < nums[m]) &&
        (m + 1 == nums.size() || nums[m] > nums[m + 1])) {
      return m;
    } else if (m - 1 == -1 || nums[m - 1] < nums[m]) {
      return Solve(nums, m + 1, r);
    } else {
      return Solve(nums, l, m - 1);
    }
  }

  int findPeakElement(vector<int>& nums) {
    return Solve(nums, 0, nums.size() - 1);
  }
};