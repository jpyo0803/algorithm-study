// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = m + n;
    while (idx > 0) {
      if (m == 0) {
        nums1[idx - 1] = nums2[n - 1];
        --n;
      } else if (n == 0) {
        nums1[idx - 1] = nums1[m - 1];
        --m;
      } else {
        if (nums1[m - 1] > nums2[n - 1]) {
          nums1[idx - 1] = nums1[m - 1];
          --m;
        } else {
          nums1[idx - 1] = nums2[n - 1];
          --n;
        }
      }
      --idx;
    }
    // nums1 is returned
  }
};