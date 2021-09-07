// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    bool ans = false;

    int rh1 = 0;

    vector<int> char_count1, char_count2;
    char_count1 = char_count2 = vector<int>(26, 0);
    for (auto ch : s1) {
      rh1 += ch;
      ++char_count1[ch - 'a'];
    }

    int rh2 = 0;
    for (int i = 0; !ans && i < s2.size(); ++i) {
      rh2 += s2[i];
      ++char_count2[s2[i] - 'a'];

      if (i < s1.size() - 1) continue;

      if (rh1 == rh2) {
        bool match = true;
        for (int j = 0; match && j < s1.size(); ++j) {
          if (char_count1[s1[j] - 'a'] != char_count2[s1[j] - 'a'])
            match = false;
        }
        if (match) ans = true;
      }
      rh2 -= s2[i - s1.size() + 1];
      --char_count2[s2[i - s1.size() + 1] - 'a'];
    }
    return ans;
  }
};