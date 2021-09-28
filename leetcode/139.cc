// 139. Word Break
// https://leetcode.com/problems/word-break/

class Solution {
 public:
  vector<int> cache_;
  unordered_set<string> us_;

  int Solve(const string& s, int x) {
    int& ret = cache_[x];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = x - 1; i >= -1; --i) {
      string target = s.substr(i + 1, x - (i + 1) + 1);
      if (us_.find(target) == us_.end()) continue;
      if (i == -1) {
        ret = 1;
        break;
      }
      ret |= Solve(s, i);
      if (ret == 1) break;
    }
    return ret;
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    for (const auto& word : wordDict) us_.insert(word);
    cache_ = vector<int>(s.length(), -1);
    return Solve(s, s.length() - 1) == 1;
  }
};