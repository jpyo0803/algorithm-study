// 231. Power of Two
// https://leetcode.com/problems/power-of-two/

// Recursive way
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    if (n == 1) return true;
    if (n % 2) return false;
    return isPowerOfTwo(n / 2);
  }
};

// Using log2
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    double lg = log2(n);
    return lg == std::trunc(lg);
  }
};