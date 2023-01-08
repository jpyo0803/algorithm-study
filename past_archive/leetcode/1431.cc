//
// 1431. Kids With the Greatest Number of Candies
// Problem:
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
//

class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans;
    int max_have = 0;
    for (int i = 0; i < candies.size(); i++) {
      max_have = max(max_have, candies[i]);
    }
    for (auto& candy : candies) {
      if (candy + extraCandies >= max_have) {
        ans.push_back(true);
      } else {
        ans.push_back(false);
      }
    }
    return ans;
  }
};