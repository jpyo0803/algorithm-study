//
// 1480. Running Sum of 1d Array
// Problem: https://leetcode.com/problems/running-sum-of-1d-array/
//

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int running_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            running_sum += nums[i];
            ans.push_back(running_sum);
        }
        return ans;
    }
};
