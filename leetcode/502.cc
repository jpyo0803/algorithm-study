// 502. IPO
// https://leetcode.com/problems/ipo/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> cpv(n);
        for (int i = 0; i < n; ++i) {
            cpv[i].first = capital[i];
            cpv[i].second = profits[i];
        }
        sort(cpv.begin(), cpv.end());

        priority_queue<int> pq;
        int i = 0;
        while (k--) {
            while (i < n && cpv[i].first <= w) {
                pq.push(cpv[i].second);
                i++;
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};