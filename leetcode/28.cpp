//
// Implement strStr()
// Problem: https://leetcode.com/problems/implement-strstr/
//

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.length() > haystack.length()) return -1;
    if (needle.length() == 0) return 0;
    int n = haystack.length();
    int m = needle.length();

    vector<int> pi(m, 0);

    int begin = 1, matched = 0;

    while (begin + matched < m) {
      if (needle[begin + matched] == needle[matched]) {
        matched += 1;
        pi[begin + matched - 1] = matched;
      } else {
        if (matched == 0) {
          begin += 1;
        } else {
          begin += matched - pi[matched - 1];
          matched = pi[matched - 1];
        }
      }
    }

    begin = matched = 0;
    while (begin <= n - m) {
      if (matched < m && haystack[begin + matched] == needle[matched]) {
        matched += 1;
        if (matched == m) {
          return begin;
        }
      } else {
        if (matched == 0) {
          begin += 1;
        } else {
          begin += matched - pi[matched - 1];
          matched = pi[matched - 1];
        }
      }
    }
    return -1;
  }
};