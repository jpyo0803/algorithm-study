// 713. Subarray Product Less Than K
// https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k < 2) return 0;
    int i = -1, j = 0;
    int m = nums[0];

    int ans = 0;

    while (j < nums.size()) {
      if (m < k) {
        ans += j - i;
        ++j;
        if (j == nums.size()) break;
        m *= nums[j];
      } else {
        ++i;
        m /= nums[i];
      }
    }

    return ans;
  }
};