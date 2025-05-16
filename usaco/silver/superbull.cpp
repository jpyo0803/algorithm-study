// Superbull (Silver)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=531

#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int u, v, w;
  Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int ds[2010];  // disjoint set

int FindSet(int x) {
  if (ds[x] == x) return x;
  ds[x] = FindSet(ds[x]);
  return ds[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> vertice(N);
  for (int i = 0; i < N; ++i) {
    cin >> vertice[i];
    ds[i] = i;  // singleton
  }

  vector<Edge> edges;
  for (int u = 0; u < N - 1; ++u) {
    for (int v = u + 1; v < N; ++v) {  // O(V^2)
      int w = vertice[u] ^ vertice[v];
      edges.emplace_back(u, v, -w);
    }
  }

  sort(edges.begin(), edges.end(), [](const Edge& x, const Edge& y) {
    return x.w < y.w;
  });  // non decreasing order

  long long ans = 0;
  for (const auto& edge : edges) {
    int x = FindSet(edge.u);
    int y = FindSet(edge.v);
    if (x != y) {
      ds[x] = y;
      ans += edge.w;
    }
  }

  cout << -ans << "\n";

  return 0;
}