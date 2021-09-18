// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

class Solution {
 public:
  static int Min(int x, int y) { return x < y ? x : y; }
  static int Max(int x, int y) { return x < y ? y : x; }

  int GetArea(const vector<int>& height, int i, int j) {
    return (j - i) * Min(height[i], height[j]);
  }

  int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int max_area = 0;
    while (i < j) {
      max_area = Max(max_area, GetArea(height, i, j));
      if (height[i] < height[j]) {
        ++i;
      } else {
        --j;
      }
    }
    return max_area;
  }
};