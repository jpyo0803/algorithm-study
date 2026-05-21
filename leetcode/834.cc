// 834. Sum of Distances in Tree
// https://leetcode.com/problems/sum-of-distances-in-tree/

// Dynamic Programming
class Solution {
 public:
  vector<vector<int>> graph_;
  vector<unordered_map<int, int>> cache_, cache2_;

  int Solve(int u, int v) {
    int& ret = cache_[u][v];
    if (ret != -1) return ret;

    ret = 0;
    for (auto w : graph_[v]) {
      if (w == u) continue;
      ret += Solve(v, w) + cache2_[v][w];
      cache2_[u][v] += cache2_[v][w];
    }
    cache2_[u][v] += 1;
    return ret;
  }

  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    graph_ = vector<vector<int>>(n);
    cache_ = cache2_ = vector<unordered_map<int, int>>(n);

    for (auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];
      graph_[u].push_back(v);
      graph_[v].push_back(u);
      cache_[u][v] = cache_[v][u] = -1;
      cache2_[u][v] = cache2_[v][u] = 0;
    }

    vector<int> ans;
    for (int u = 0; u < n; ++u) {
      int ret = 0;
      for (auto v : graph_[u]) {
        ret += Solve(u, v) + cache2_[u][v];
      }

      ans.push_back(ret);
    }

    return ans;
  }
};

// Formal Way
class Solution {
 public:
  vector<vector<int>> graph_;
  vector<int> ans_, count_;
  int n_;

  void Dfs1(int u, int parent) {
    count_[u] = 1;
    for (auto v : graph_[u]) {
      if (parent == v) continue;
      Dfs1(v, u);
      count_[u] += count_[v];
      ans_[u] += ans_[v] + count_[v];
    }
  }

  void Dfs2(int u, int parent) {
    for (auto v : graph_[u]) {
      if (parent == v) continue;
      ans_[v] = ans_[u] - count_[v] + n_ - count_[v];
      Dfs2(v, u);
    }
  }

  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    n_ = n;
    graph_ = vector<vector<int>>(n);
    ans_ = count_ = vector<int>(n, 0);

    for (auto& edge : edges) {
      graph_[edge[0]].push_back(edge[1]);
      graph_[edge[1]].push_back(edge[0]);
    }

    Dfs1(0, -1);
    Dfs2(0, -1);

    return ans_;
  }
};