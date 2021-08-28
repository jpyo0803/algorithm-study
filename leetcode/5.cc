// Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
 public:
  string longestPalindrome(string s) {
    int max_len = 0;
    int max_start;
    for (int i = 0; i < s.size(); ++i) {  // odd
      int j = i, k = i;
      while (j - 1 >= 0 && k + 1 < s.size() && s[j - 1] == s[k + 1]) {
        --j;
        ++k;
      }

      int len = k - j + 1;
      if (max_len < len) {
        max_len = len;
        max_start = j;
      }
    }

    for (int i = 0; i < s.size() - 1; ++i) {
      int j = i + 1, k = i;
      while (j - 1 >= 0 && k + 1 < s.size() && s[j - 1] == s[k + 1]) {
        --j;
        ++k;
      }

      int len = k - j + 1;
      if (max_len < len) {
        max_len = len;
        max_start = j;
      }
    }

    return s.substr(max_start, max_len);
  }
};