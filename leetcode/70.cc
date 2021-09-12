// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

class Solution {
 public:
  int climbStairs(int n) {
    vector<int> cache(n + 1, 0);
    cache[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= 2; ++j) {
        int prev = i - j;
        if (prev < 0) continue;
        cache[i] += cache[prev];
      }
    }
    return cache[n];
  }
};