//
// 1. Two Sum
// Problem: https://leetcode.com/problems/two-sum/
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_set<int> freq;
        unordered_map<int, int> indice;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (freq.find(diff) != freq.end()) { // found
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