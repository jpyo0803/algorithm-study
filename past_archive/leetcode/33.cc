// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

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

  int BinarySearch(const vector<int>& nums, int l, int r, int t) {
    if (l > r) return -1;

    int m = (l + r) / 2;
    if (nums[m] < t) {
      return BinarySearch(nums, m + 1, r, t);
    } else if (nums[m] > t) {
      return BinarySearch(nums, l, m - 1, t);
    } else {
      return m;
    }
  }

  int search(vector<int>& nums, int target) {
    int len = nums.size();
    if (len == 1) {
      if (nums[0] == target) return 0;
      return -1;
    }

    int ip = FindInflexionPoint(nums, 0, len - 1);
    int ans;
    if (nums[ip] <= target && target <= nums.back()) {
      ans = BinarySearch(nums, ip, len - 1, target);
    } else if (ip - 1 >= 0 && nums[ip - 1] >= target && nums[0] <= target) {
      ans = BinarySearch(nums, 0, ip - 1, target);
    } else {
      ans = (nums[ip] == target ? ip : -1);
    }
    return ans;
  }
};