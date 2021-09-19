// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> mm(26, 0);
    for (auto ch : magazine) {
      ++mm[ch - 'a'];
    }

    for (auto ch : ransomNote) {
      if (mm[ch - 'a'] > 0) {
        --mm[ch - 'a'];
      } else {
        return false;
      }
    }
    return true;
  }
};