// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> um;
    for (int i = 0; i < numbers.size(); ++i) {
      um[numbers[i]] = i;
    }

    vector<int> ans;
    for (int i = 0; i < numbers.size(); ++i) {
      int other = target - numbers[i];
      if (um.count(other) == 0) continue;
      int oi = um[other];
      if (i == oi) continue;
      if (i < oi) {
        ans.push_back(i + 1);
        ans.push_back(oi + 1);
        break;
      } else {
        ans.push_back(oi + 1);
        ans.push_back(i + 1);
        break;
      }
    }

    return ans;
  }
};