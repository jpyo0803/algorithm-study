// 673. Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
 public:
  static int Max(int x, int y) { return x < y ? y : x; }

  int findNumberOfLIS(vector<int>& nums) {
    int len = nums.size();
    vector<int> cache(len, 0);
    vector<int> cache2(len + 1, 0);

    int m = 1;
    for (int i = 0; i < len; ++i) {
      int pm = 0;
      int pc = 1;
      for (int j = 0; j < i; ++j) {
        if (nums[j] >= nums[i]) continue;
        if (pm < cache[j]) {
          pm = cache[j];
          pc = cache2[j];
        } else if (pm == cache[j]) {
          pc += cache2[j];
        }
      }
      cache[i] = pm + 1;
      cache2[i] = pc;
      m = m < cache[i] ? cache[i] : m;
    }

    int ans = 0;
    for (int i = 0; i < len; ++i) {
      if (cache[i] == m) ans += cache2[i];
    }

    return ans;
  }
};