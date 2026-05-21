//
// 743. Network Delay Time
// Problem: https://leetcode.com/problems/network-delay-time/
//

#include <queue>

constexpr int INF = 987654321;

vector<vector<int>> adj, w;
vector<int> d;

struct Compare {
  bool operator()(int x, int y) { return d[x] < d[y]; }
};
priority_queue<int, vector<int>, Compare> pq;

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    d = vector<int>(n + 1, INF);
    adj = vector<vector<int>>(n + 1);
    w = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
    for (auto& time : times) {
      adj[time[0]].push_back(time[1]);
      w[time[0]][time[1]] = time[2];
    }

    d[k] = 0;
    pq.push(k);
    while (!pq.empty()) {
      int u = pq.top();
      pq.pop();
      for (auto v : adj[u]) {
        if (d[v] > d[u] + w[u][v]) {
          d[v] = d[u] + w[u][v];
          pq.push(v);
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (d[i] == INF) return -1;
      ans = ans < d[i] ? d[i] : ans;
    }
    return ans;
  }
};
