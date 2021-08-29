// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

class Solution {
 public:
  vector<string> strs[9];

  void Solve(int n, int x) {
    if (n + 1 == x) return;

    for (int i = 0; i < x; ++i) {
      int j = x - 1 - i;
      for (auto& str_i : strs[i]) {
        for (auto& str_j : strs[j]) {
          char tmp[20];
          sprintf(tmp, "(%s)%s", str_i.c_str(), str_j.c_str());
          strs[x].push_back(tmp);
        }
      }
    }
    Solve(n, x + 1);
  }

  vector<string> generateParenthesis(int n) {
    strs[0].push_back("");
    Solve(n, 1);
    return strs[n];
  }
};