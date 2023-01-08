// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
 public:
  static int Min(int x, int y) { return x < y ? x : y; }

  int minSubArrayLen(int target, vector<int>& nums) {
    int i = -1, j = 0;
    int sum = nums[j];

    int ans = 987654321;
    while (j < nums.size()) {
      if (sum >= target) {
        ans = Min(ans, j - i);
        ++i;
        sum -= nums[i];
      } else {
        ++j;
        if (j == nums.size()) break;
        sum += nums[j];
      }
    }
    return (ans == 987654321 ? 0 : ans);
  }
};