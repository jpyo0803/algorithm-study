// 797. All Paths From Source to Target
// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
 public:
  int N_;

  void Dfs(const vector<vector<int>>& graph, vector<vector<int>>& ans,
           vector<int>&& cand, int u) {
    cand.push_back(u);
    if (u == N_ - 1) {
      ans.push_back(cand);
      cand.pop_back();
      return;
    }

    for (auto v : graph[u]) {
      Dfs(graph, ans, std::move(cand), v);
    }
    cand.pop_back();
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    N_ = graph.size();

    vector<vector<int>> ans;

    Dfs(graph, ans, std::move(vector<int>()), 0);

    return ans;
  }
};