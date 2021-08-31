// 38. Count and Say
// https://leetcode.com/problems/count-and-say/

class Solution {
 public:
  string Solve(int n) {
    if (n == 1) return "1";

    string ret = Solve(n - 1);
    string s;

    char num = 'a';
    int count = 0;
    for (int i = 0; i < ret.size(); ++i) {
      if (ret[i] != num) {
        if (count > 0) {
          s.push_back(num);
          s.push_back(static_cast<char>('0' + count));
        }
        num = ret[i];
        count = 0;
      }
      ++count;
    }
    if (count > 0) {
      s.push_back(num);
      s.push_back(static_cast<char>('0' + count));
    }
    return s;
  }

  string countAndSay(int n) {
    string ans = Solve(n);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};