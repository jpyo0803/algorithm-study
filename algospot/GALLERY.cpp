//
// GALLERY
// Problem: https://www.algospot.com/judge/problem/read/GALLERY
//

#include <cstdio>
#include <vector>

using namespace std;

constexpr int kUnwatched = 0;
constexpr int kWatched = 1;
constexpr int kInstalled = 2;

int C, G, H, installed;
vector<vector<int>> adj;
vector<bool> visited;

int Dfs(int u) {
  visited[u] = true;
  int children[3] = {0, 0, 0};
  for (auto v : adj[u]) {
    if (!visited[v]) {
      children[Dfs(v)]++;
    }
  }

  if (children[kUnwatched]) {
    installed++;
    return kInstalled;
  }

  if (children[kInstalled]) {
    return kWatched;
  }
  return kUnwatched;
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    scanf("%d%d", &G, &H);
    adj = vector<vector<int>>(G);
    visited = vector<bool>(G, false);
    installed = 0;

    for (int h = 0; h < H; h++) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int u = 0; u < G; u++) {
      if (!visited[u] && Dfs(u) == kUnwatched) installed++;
    }
    printf("%d\n", installed);
  }
  return 0;
}
