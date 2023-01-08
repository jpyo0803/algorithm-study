// 322. Coin Change
// https://leetcode.com/problems/coin-change/

class Solution {
 public:
  static constexpr int kInf = 987654321;

  static int Min(int x, int y) { return x < y ? x : y; }
  vector<int> cache_;

  int Solve(const vector<int>& coins, int amt) {
    if (amt < 0) return kInf * 2;
    if (amt == 0) return 0;

    int& ret = cache_[amt];
    if (ret != -1) return ret;

    ret = kInf;
    for (auto coin : coins) {
      ret = Min(ret, Solve(coins, amt - coin) + 1);
    }
    return ret;
  }

  int coinChange(vector<int>& coins, int amount) {
    cache_ = vector<int>(amount + 1, -1);
    int ans = Solve(coins, amount);
    if (ans == kInf) ans = -1;
    return ans;
  }
};