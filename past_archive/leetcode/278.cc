// 278. First Bad Version
// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
 public:
  unsigned int min_bad;

  void BinarySearch(unsigned int l, unsigned int r) {
    if (l > r) return;

    unsigned int m = (l + r) / 2;
    if (isBadVersion(m)) {
      min_bad = m < min_bad ? m : min_bad;
      BinarySearch(l, m - 1);
    } else {
      BinarySearch(m + 1, r);
    }
  }

  int firstBadVersion(int n) {
    min_bad = 1 << 31;
    BinarySearch(1, n);
    return min_bad;
  }
};