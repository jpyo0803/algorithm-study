// 28. Implement strStr()
// Problem: https://leetcode.com/problems/implement-strstr/

// Simple Bruteforce
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int lh = haystack.size();
    int ln = needle.size();
    if (ln == 0) return 0;

    int ans = -1;
    for (int i = 0; i <= lh - ln; ++i) {
      int match = 0;
      for (int j = 0; j < ln; ++j) {
        if (haystack[i + j] == needle[j]) {
          ++match;
        } else {
          break;
        }
      }
      if (match == ln) {
        ans = i;
        break;
      }
    }
    return ans;
  }
};

// Rolling Hash
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int lh = haystack.size();
    int ln = needle.size();
    if (ln == 0) return 0;

    int rhn = 0;
    for (int i = 0; i < ln; ++i) {
      rhn += static_cast<int>(needle[i]);
    }

    int rhh = 0;

    int ans = -1;
    for (int i = 0; i < lh; ++i) {
      rhh += static_cast<int>(haystack[i]);
      if (i < ln - 1) continue;

      if (rhh == rhn) {
        int match = 0;
        for (int j = 0; j < ln; ++j) {
          if (haystack[i - ln + 1 + j] == needle[j]) {
            ++match;
          } else {
            break;
          }
        }
        if (match == ln) {
          ans = i - ln + 1;
          break;
        }
      }
      rhh -= static_cast<int>(haystack[i - ln + 1]);
    }
    return ans;
  }
};

// KMP
class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;

    int ans = -1;

    vector<int> failure_table(needle.size(), 0);

    int b = 1;
    int m = 0;

    while (b + m < needle.size()) {
      if (needle[b + m] == needle[m]) {
        ++m;
        failure_table[b + m - 1] = m;
      } else {
        if (m == 0) {
          ++b;
        } else {
          b += m - failure_table[m - 1];
          m = failure_table[m - 1];
        }
      }
    }

    b = m = 0;

    while (b + m <= haystack.size()) {
      if (m < needle.size() && needle[m] == haystack[b + m]) {
        ++m;
        if (m == needle.size()) {
          ans = b;
          break;
        }
      } else {
        if (m == 0) {
          ++b;
        } else {
          b += m - failure_table[m - 1];
          m = failure_table[m - 1];
        }
      }
    }

    return ans;
  }
};