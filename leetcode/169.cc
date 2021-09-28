// 169. Majority Element
// https://leetcode.com/problems/majority-element/

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int len = nums.size();

    int ans = 0;

    unordered_map<int, int> um;
    for (auto num : nums) {
      ++um[num];
      if (um[num] > len / 2) {
        ans = num;
        break;
      }
    }
    return ans;
  }
};