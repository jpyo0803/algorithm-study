// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<int> cc(26, 0);
    for (auto ch : s) {
      ++cc[ch - 'a'];
    }
    for (auto ch : t) {
      if (cc[ch - 'a'] > 0) {
        --cc[ch - 'a'];
      } else {
        return false;
      }
    }
    return true;
  }
};