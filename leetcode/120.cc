// 120. Triangle
// https://leetcode.com/problems/triangle/

class Solution {
 public:
  static constexpr int kInf = 987654321;
  static constexpr int d[2][2] = {{-1, -1}, {-1, 0}};

  static int Min(int x, int y) { return x < y ? x : y; }

  int minimumTotal(vector<vector<int>>& triangle) {
    const int height = triangle.size();
    vector<vector<int>> cache(height);
    for (int i = 0; i < height; ++i) {
      cache[i] = vector<int>(triangle[i].size(), kInf);
    }
    cache[0][0] = triangle[0][0];

    for (int i = 1; i < height; ++i) {
      const int width = triangle[i].size();
      for (int j = 0; j < width; ++j) {
        for (int k = 0; k < 2; ++k) {
          int pi = i + d[k][0];
          int pj = j + d[k][1];
          if (pi < 0 || pj < 0 || pj > width - 2) continue;
          cache[i][j] = Min(cache[i][j], cache[pi][pj] + triangle[i][j]);
        }
      }
    }

    int ans = kInf;
    for (int j = 0; j < triangle[height - 1].size(); ++j) {
      ans = Min(ans, cache[height - 1][j]);
    }
    return ans;
  }
};