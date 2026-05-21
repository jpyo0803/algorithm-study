// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
 public:
  static int Max(int x, int y) { return x < y ? y : x; }

  int lengthOfLIS(vector<int>& nums) {
    int len = nums.size();
    vector<int> cache(len, 0);

    cache[0] = 1;
    int ans = 1;
    for (int i = 1; i < len; ++i) {
      int prev_max = 0;
      for (int j = 0; j < i; ++j) {
        if (nums[j] >= nums[i]) continue;
        prev_max = Max(prev_max, cache[j]);
      }
      cache[i] = prev_max + 1;
      ans = Max(ans, cache[i]);
    }
    return ans;
  }
};