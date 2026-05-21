// 547. Number of Provinces
// https://leetcode.com/problems/number-of-provinces/

class Solution {
 public:
  int N_;
  vector<bool> check_;

  void Solve(const vector<vector<int>>& isConnected, int u) {
    check_[u] = true;

    for (int v = 0; v < N_; ++v) {
      if (isConnected[u][v] == 0) continue;
      if (check_[v]) continue;
      Solve(isConnected, v);
    }
  }

  int findCircleNum(vector<vector<int>>& isConnected) {
    N_ = isConnected.size();
    check_ = vector<bool>(N_, false);

    int ans = 0;
    for (int i = 0; i < N_; ++i) {
      if (check_[i]) continue;
      Solve(isConnected, i);
      ++ans;
    }

    return ans;
  }
};