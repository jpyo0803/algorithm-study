// 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
 public:
  void ReversePartialString(string& s, int start, int end) {
    if (start > end) return;

    int len = end - start + 1;
    for (int i = 0; i < len / 2; ++i) {
      char tmp = s[start + i];
      s[start + i] = s[start + len - 1 - i];
      s[start + len - 1 - i] = tmp;
    }
  }

  string reverseWords(string s) {
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (i == s.size() - 1 || s[i + 1] == ' ') {
        ReversePartialString(s, start, i);
        start = i + 2;
      }
    }
    return s;
  }
};