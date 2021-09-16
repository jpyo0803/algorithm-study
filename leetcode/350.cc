// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

// First way
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> count_arr(1001, 0);
    for (auto num : nums1) {
      ++count_arr[num];
    }

    vector<int> ans;
    for (auto num : nums2) {
      if (count_arr[num] > 0) {
        ans.push_back(num);
        --count_arr[num];
      }
    }
    return ans;
  }
};
