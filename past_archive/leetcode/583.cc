// 583. Delete Operation for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
 public:
  static int Max(int x, int y) { return x < y ? y : x; }

  int cache_[500][500];

  int Solve(const string& w1, const string& w2, int x, int y) {
    if (x < 0 || y < 0) return 0;

    int& ret = cache_[x][y];
    if (ret != -1) return ret;

    ret = Max(Solve(w1, w2, x - 1, y), Solve(w1, w2, x, y - 1));
    ret = Max(ret, Solve(w1, w2, x - 1, y - 1) + (w1[x] == w2[y]));
    return ret;
  }

  int minDistance(string word1, string word2) {
    for (int i = 0; i < word1.length(); ++i) {
      memset(cache_[i], 0xff, sizeof(int) * word2.length());
    }
    return word1.length() + word2.length() -
           (Solve(word1, word2, word1.length() - 1, word2.length() - 1)) * 2;
  }
};