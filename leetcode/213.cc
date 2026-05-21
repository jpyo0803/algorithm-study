// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/

class Solution {
 public:
  static int Max(int x, int y) { return x < y ? y : x; }

  int rob(vector<int>& nums) {
    int len = nums.size();
    if (len == 1) return nums[0];
    if (len == 2) return Max(nums[0], nums[1]);

    vector<int> cache(len, 0);

    int ans1 = 0;
    for (int i = 1; i < len; ++i) {
      int local_max = 0;
      for (int j = 0; j < i - 1; ++j) {
        local_max = Max(local_max, cache[j]);
      }
      cache[i] = local_max + nums[i];
      ans1 = Max(ans1, cache[i]);
    }

    fill(cache.begin(), cache.end(), 0);
    cache[0] = nums[0];
    int ans2 = cache[0];
    for (int i = 1; i < len - 1; ++i) {
      int local_max = 0;
      for (int j = 0; j < i - 1; ++j) {
        local_max = Max(local_max, cache[j]);
      }
      cache[i] = local_max + nums[i];
      ans2 = Max(ans2, cache[i]);
    }

    return Max(ans1, ans2);
  }
};