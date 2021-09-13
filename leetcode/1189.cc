// 1189. Maximum Number of Balloons
// https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
 public:
  static constexpr char balloon[8] = "balloon";

  int maxNumberOfBalloons(string text) {
    vector<int> expected_count(26, 0);
    for (int i = 0; i < 7; ++i) {
      ++expected_count[balloon[i] - 'a'];
    }
    vector<int> char_count(26, 0);
    for (auto ch : text) ++char_count[ch - 'a'];

    int ans = 987654321;
    for (int i = 0; i < 7; ++i) {
      int cc = char_count[balloon[i] - 'a'] / expected_count[balloon[i] - 'a'];
      if (cc == 0) return 0;
      ans = cc < ans ? cc : ans;
    }
    return ans;
  }
};