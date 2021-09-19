// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> sm, pm, ans;
    sm = pm = vector<int>(26, 0);
    for (auto ch : p) {
      ++pm[ch - 'a'];
    }

    int mc = 0;
    const int ofs = p.size();
    for (int i = 0; i < s.length(); ++i) {
      if (i - ofs >= 0) {
        char pch = s[i - ofs];
        --sm[pch - 'a'];
        if (sm[pch - 'a'] < pm[pch - 'a']) --mc;
      }
      char ch = s[i];
      ++sm[ch - 'a'];
      if (sm[ch - 'a'] <= pm[ch - 'a']) ++mc;
      if (mc == ofs) ans.push_back(i - ofs + 1);
    }

    return ans;
  }
};