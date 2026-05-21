// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/

// Naive way
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
      if (n % 2) ++count;
      n /= 2;
    }
    return count;
  }
};

// Population Count way
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n & 0x3f;
  }
};