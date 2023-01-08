// 784. Letter Case Permutation
// https://leetcode.com/problems/letter-case-permutation/

class Solution {
 public:
  static bool IsAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
  }

  static char ConvertCase(char ch) {
    if (ch >= 'a' && ch <= 'z') return ch - 32;
    return ch + 32;
  }

  void Solve(vector<string>& ans, char cand[], int len, const string& s) {
    if (len == s.size()) {
      cand[len] = '\0';
      ans.push_back(cand);
      return;
    }

    if (IsAlpha(s[len])) {
      cand[len] = ConvertCase(s[len]);
      Solve(ans, cand, len + 1, s);
    }
    cand[len] = s[len];
    Solve(ans, cand, len + 1, s);
  }
  vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    char cand[13];
    Solve(ans, cand, 0, s);
    return ans;
  }
};