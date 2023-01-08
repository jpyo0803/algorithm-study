// 413. Arithmetic Slices
// https://leetcode.com/problems/arithmetic-slices/

class Solution {
 public:
  static constexpr int kInf = 987654321;

  int numberOfArithmeticSlices(vector<int>& nums) {
    int ans = 0;
    int c = 0;

    int d = kInf;
    for (int i = 0; i < nums.size(); ++i) {
      int nd;
      if (i + 1 == nums.size()) {
        nd = kInf + 1;
      } else {
        nd = nums[i + 1] - nums[i];
      }
      ++c;
      if (d != nd) {
        if (c >= 3) {
          ans += (c - 2) * (c - 1) / 2;
        }
        d = nd;
        c = 1;
      }
    }

    return ans;
  }
};