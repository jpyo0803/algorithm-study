// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

class Solution {
 public:
  int FindBefore(const string& s, int i, char r) {
    int c = 0;
    while (i >= 0 && s[i] == r) {
      ++c;
      --i;
    }
    return c;
  }

  int romanToInt(string s) {  // number = 1 ~ 3999
    int ans = 0;

    int i = s.size() - 1;
    while (i >= 0) {
      int c;
      if (s[i] == 'M' || s[i] == 'D') {
        c = FindBefore(s, i - 1, 'C');
        int v = s[i] == 'M' ? 1000 : 500;
        ans += v - (100 * c);
      } else if (s[i] == 'C' || s[i] == 'L') {
        c = FindBefore(s, i - 1, 'X');
        int v = s[i] == 'C' ? 100 : 50;
        ans += v - (10 * c);
      } else if (s[i] == 'X' || s[i] == 'V') {
        c = FindBefore(s, i - 1, 'I');
        int v = s[i] == 'X' ? 10 : 5;
        ans += v - (1 * c);
      } else {  // I
        c = FindBefore(s, i - 1, 'I');
        ans += 1 + c;
      }
      i = i - c - 1;
    }

    return ans;
  }
};