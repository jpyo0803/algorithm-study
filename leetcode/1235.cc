//
// 1235. Maximum Profit in Job Scheduling
// Problem: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
//

#define MODE 0 // 0 = memoization, 1 = tabulation

class Interval {
public:
    Interval(int _st, int _et, int _p) : st(_st), et(_et), p(_p) {}
    int st, et, p;
};

#if (MODE == 0)
bool compare_memo(Interval& a, Interval& b) { return a.st < b.st; }
#else
bool compare_tabulate(Interval& a, Interval& b) { return a.et < b.et; }
#endif

class Solution {
public:
    int dp[50000];
    vector<Interval> intervals;

#if (MODE == 0)
    bool filled[50000];
    int memo_method(int i) {
        if (i >= intervals.size()) return 0;
        if (filled[i]) return dp[i];

        int j = i + 1;
        while (j < intervals.size() && intervals[i].et > intervals[j].st) {
            j++;
        }
        dp[i] = max(intervals[i].p + memo_method(j), memo_method(i + 1));
        filled[i] = true;
        return dp[i];
    }
#else
    int tabulate_method(int n) {
        int ans = 0;
        dp[0] = intervals[0].p;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (int j = i - 1; j >= 0; j--) {
                if (intervals[j].et <= intervals[i].st) {
                    dp[i] = max(dp[i], dp[j] + intervals[i].p);
                    break;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
#endif

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        for (int i = 0; i < startTime.size(); i++) {
            intervals.emplace_back(startTime[i], endTime[i], profit[i]);
        }
#if (MODE == 0)
        sort(intervals.begin(), intervals.end(), compare_memo);
        int ans = memo_method(0);
#else
        sort(intervals.begin(), intervals.end(), compare_tabulate);
        int ans = tabulate_method(intervals.size() - 1);
#endif
        return ans;
    }
};