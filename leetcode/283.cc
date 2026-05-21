// 283. Move Zeros
// https://leetcode.com/problems/move-zeroes/

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    vector<int> nz, z;
    for (auto e : nums) {
      if (e == 0)
        z.push_back(e);
      else
        nz.push_back(e);
    }
    nz.insert(nz.end(), z.begin(), z.end());
    nums = nz;
  }
};