//
// 1. Two Sum
// Problem: https://leetcode.com/problems/two-sum/
//

// First try when I was a noob
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_set<int> freq;
    unordered_map<int, int> indice;
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      if (freq.find(diff) != freq.end()) {  // found
        ans.push_back(indice[diff]);
        ans.push_back(i);
        break;
      } else {
        freq.insert(nums[i]);
        indice[nums[i]] = i;
      }
    }
    return ans;
  }
};

// later when I am better
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;

    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); ++i) {
      int d = target - nums[i];
      if (um.count(d) > 0) {
        ans.push_back(um[d]);
        ans.push_back(i);
        break;
      }
      um[nums[i]] = i;
    }

    return ans;
  }
};