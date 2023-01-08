// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
 public:
  int FindInflexionPoint(const vector<int>& nums, int l, int r) {
    if (l == r) return l;

    int m = (l + r) / 2;
    if (nums[m] > nums[r]) {
      return FindInflexionPoint(nums, m + 1, r);
    } else {
      return FindInflexionPoint(nums, l, m);
    }
  }

  int findMin(vector<int>& nums) {
    int ip = FindInflexionPoint(nums, 0, nums.size() - 1);
    return nums[ip];
  }
};