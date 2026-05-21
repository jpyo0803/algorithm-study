// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/

class Solution {
 public:
  vector<int> cache_;

  int Solve(const string& s, int x) {
    if (x < 0) return 1;

    int& ret = cache_[x];
    if (ret != -1) return ret;
    ret = 0;

    if (s[x] != '0') ret += Solve(s, x - 1);
    int num = 0;
    if (x - 1 >= 0 && s[x - 1] != '0') {
      num = (s[x - 1] - '0') * 10 + (s[x] - '0');
    }
    if (num >= 1 && num <= 26) {
      ret += Solve(s, x - 2);
    }
    return ret;
  }

  int numDecodings(string s) {
    cache_ = vector<int>(s.length(), -1);
    return Solve(s, s.length() - 1);
  }
};