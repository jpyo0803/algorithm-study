// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

// Naive way O(N)
class Solution {
 public:
  static int Max(int x, int y) { return x < y ? y : x; }

  int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int ans = INT_MIN;
    for (auto num : nums) {
      int tmp = sum + num;
      if (tmp < 0)
        sum = 0;
      else
        sum = tmp;
      ans = Max(ans, tmp);
    }
    return ans;
  }
};
