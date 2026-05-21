// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

using namespace std;

class Solution {
 public:
  static int Max(int x, int y) { return x < y ? y : x; }

  int lengthOfLongestSubstring(string s) {
    int last_occured[128];
    for (int i = 0; i < 128; ++i) last_occured[i] = -1;

    int ans = 0;

    int ll = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (last_occured[s[i]] != -1) {
        ll = Max(ll, last_occured[s[i]]);
      }
      last_occured[s[i]] = i;
      ans = Max(ans, i - ll);
    }

    return ans;
  }
};