// 1042. Flower Planting With No Adjacent
// https://leetcode.com/problems/flower-planting-with-no-adjacent/

bool Comparator(const pair<int, int>& lhs, const pair<int, int>& rhs) {
  return lhs.second > rhs.second;
}

class Solution {
 public:
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<vector<int>> graph(n);

    for (auto& path : paths) {
      int u = path[0] - 1;
      int v = path[1] - 1;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    vector<pair<int, int>> in_out_degree(n);
    for (int i = 0; i < n; ++i) {
      in_out_degree[i].first = i;
      in_out_degree[i].second = graph[i].size();
    }

    sort(in_out_degree.begin(), in_out_degree.end(), Comparator);
    int max_degree = in_out_degree[0].second;

    vector<int> node_color(n, -1);

    vector<bool> check_color(max_degree + 2);
    for (auto& e : in_out_degree) {
      if (node_color[e.first] == -1) {
        for (int i = 1; i < check_color.size(); ++i) check_color[i] = false;

        for (auto v : graph[e.first]) {
          if (node_color[v] == -1) continue;
          check_color[node_color[v]] = true;
        }

        int next_color;
        for (int i = 1; i < check_color.size(); ++i) {
          if (!check_color[i]) {
            next_color = i;
            break;
          }
        }

        node_color[e.first] = next_color;
      }
    }

    return node_color;
  }
};