// ZigZag Conversion
// https://leetcode.com/problems/zigzag-conversion/

class Solution {
 public:
  string str_arr[1'010];

  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    int j = 0;
    int dir = 1;
    for (int i = 0; i < s.size(); ++i) {
      str_arr[j].push_back(s[i]);
      j += dir;
      if (j == numRows) {
        j = numRows - 2;
        dir = -1;
      } else if (j == -1) {
        j = 1;
        dir = 1;
      }
    }

    string ans;
    ans.reserve(s.size());
    for (int i = 0; i < numRows; ++i) {
      ans.append(str_arr[i]);
    }

    return ans;
  }
};