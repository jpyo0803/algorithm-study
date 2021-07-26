// LCA
// https://www.acmicpc.net/problem/11437

#include <stdio.h>

#include <vector>

using namespace std;

int N, M;
vector<int> tree[50001];
int depth[50001];
int parent[50001][17];

void Dfs(int u) {
  for (auto v : tree[u]) {
    if (depth[v] != -1) continue;
    parent[v][0] = u;
    depth[v] = depth[u] + 1;
    Dfs(v);
  }
}

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N - 1; ++n) {
    int x, y;
    scanf("%d%d", &x, &y);
    tree[x].push_back(y);
    tree[y].push_back(x);
  }

  for (int i = 0; i < 50001; ++i) {
    depth[i] = -1;
    for (int j = 0; j < 17; ++j) {
      parent[i][j] = -1;
    }
  }

  depth[1] = 0;
  Dfs(1);

  for (int j = 0; j < 17; ++j) {
    for (int i = 1; i < 50001; ++i) {
      if (parent[i][j] != -1) {
        parent[i][j + 1] = parent[parent[i][j]][j];
      }
    }
  }

  scanf("%d", &M);
  for (int m = 0; m < M; ++m) {
    int x, y;
    scanf("%d%d", &x, &y);

    if (depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    int j = 0;
    while (diff > 0) {
      if (diff % 2) x = parent[x][j];
      diff /= 2;
      ++j;
    }

    if (x != y) {
      for (int j = 16; j >= 0; --j) {
        if (parent[x][j] != -1 && parent[x][j] != parent[y][j]) {
          x = parent[x][j];
          y = parent[y][j];
        }
      }
      x = parent[x][0];
    }
    printf("%d\n", x);
  }
  return 0;
}