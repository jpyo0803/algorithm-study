// 986. Interval List Intersections
// https://leetcode.com/problems/interval-list-intersections/

class Solution {
 public:
  static int Min(int x, int y) { return x < y ? x : y; }
  static int Max(int x, int y) { return x < y ? y : x; }

  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    vector<vector<int>> ans;

    int i = 0, j = 0;
    while (i < firstList.size() && j < secondList.size()) {
      int ll = Max(firstList[i][0], secondList[j][0]);
      int ul = Min(firstList[i][1], secondList[j][1]);
      if (ul - ll >= 0) {
        ans.push_back({ll, ul});
      }
      if (firstList[i][1] < secondList[j][1])
        ++i;
      else
        ++j;
    }
    return ans;
  }
};