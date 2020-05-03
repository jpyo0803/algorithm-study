//
// Non-overlapping Intervals
// Problem: https://leetcode.com/problems/non-overlapping-intervals/
//

bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int thrown_aways = 0;
        sort(intervals.begin(), intervals.end(), compare);

        int prev_end_time = -1000000000;
        for (auto interval : intervals) {
            if (prev_end_time <= interval[0]) {
                prev_end_time = interval[1];
            } else {
                thrown_aways += 1;
            }
        }
        return thrown_aways;
    }
};
