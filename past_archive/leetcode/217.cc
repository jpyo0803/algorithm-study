// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

// Using STL set (map is possible too)
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for (auto num : nums) {
      if (s.find(num) != s.end()) return true;
      s.insert(num);
    }
    return false;
  }
};

// Sort array way (faster)
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == nums[i + 1]) return true;
    }
    return false;
  }
};
