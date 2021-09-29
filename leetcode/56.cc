// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

class Solution {
 public:
  static bool Compare(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }

  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 1) return intervals;
    sort(intervals.begin(), intervals.end(), Compare);
    vector<vector<int>> ans;

    int si = intervals[0][0];
    int ei = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= ei) {
        ei = ei < intervals[i][1] ? intervals[i][1] : ei;
      } else {
        ans.push_back({si, ei});
        si = intervals[i][0];
        ei = intervals[i][1];
      }
      if (i == intervals.size() - 1) {
        ans.push_back({si, ei});
      }
    }
    return ans;
  }
};