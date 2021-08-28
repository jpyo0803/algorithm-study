// 17. Letter Combination of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

namespace {
unordered_map<char, string> um = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                  {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                  {'8', "tuv"}, {'9', "wxyz"}};
}

class Solution {
 public:
  void Solve(vector<string>& ans, const string& digits, string&& s, int i) {
    if (digits.size() == i) {
      if (s.empty()) return;
      ans.push_back(s);
      return;
    }

    for (auto ch : um[digits[i]]) {
      s.push_back(ch);
      Solve(ans, digits, forward<string>(s), i + 1);
      s.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    Solve(ans, digits, string(), 0);
    return ans;
  }
};