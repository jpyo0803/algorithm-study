// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> char_ind(26, -1);
    vector<int> char_count(26, 0);

    for (int i = 0; i < s.length(); ++i) {
      char ch = s[i];
      if (char_ind[ch - 'a'] == -1) {
        char_ind[ch - 'a'] = i;
      }
      ++char_count[ch - 'a'];
    }

    int ans = 987654321;
    for (int i = 0; i < 26; ++i) {
      if (char_count[i] == 1) {
        if (char_ind[i] < ans) {
          ans = char_ind[i];
        }
      }
    }
    return (ans == 987654321 ? -1 : ans);
  }
};