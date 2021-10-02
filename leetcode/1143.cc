// 1143. Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/

// First idea

class Solution {
 public:
  int cache_[1000][1000];
  static int Max(int x, int y) { return x < y ? y : x; }

  int Solve(const string& t1, const string& t2, int x, int y) {
    if (x < 0 || y < 0) return 0;

    int& ret = cache_[x][y];
    if (ret != -1) return ret;

    ret = Max(Solve(t1, t2, x - 1, y), Solve(t1, t2, x, y - 1));
    ret = Max(ret, Solve(t1, t2, x - 1, y - 1) + (t1[x] == t2[y]));
    return ret;
  }

  int longestCommonSubsequence(string text1, string text2) {
    for (int i = 0; i < text1.length(); ++i) {
      memset(cache_[i], 0xff, sizeof(int) * text2.length());
    }
    return Solve(text1, text2, text1.length() - 1, text2.length() - 1);
  }
};