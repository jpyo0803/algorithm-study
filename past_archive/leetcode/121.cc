// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
 public:
  static int Min(int x, int y) { return x < y ? x : y; }

  static int Max(int x, int y) { return x < y ? y : x; }

  int maxProfit(vector<int>& prices) {
    int prev_min = 987654321;
    int ans = 0;
    for (auto price : prices) {
      if (prev_min == 987654321) {
        prev_min = price;
        continue;
      }
      ans = Max(ans, price - prev_min);
      prev_min = Min(prev_min, price);
    }
    return ans;
  }
};