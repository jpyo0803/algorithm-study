// LCA 2
// https://www.acmicpc.net/problem/11438

#include <stdio.h>
#include <vector>

using namespace std;

int N, M;

vector<int> tree[100010];
int depth[100010];
int parent[100010][18];

void Dfs(int x) {
  for (auto y : tree[x]) {
    if (depth[y] != -1) continue;
    parent[y][0] = x;
    depth[y] = depth[x] + 1;
    Dfs(y);
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

  for (int i = 1; i <= N; ++i) {
    depth[i] = -1;
    for (int j = 0; j < 18; ++j) {
      parent[i][j] = -1;
    }
  }

  depth[1] = 0;
  Dfs(1);

  for (int j = 0; j < 18; ++j) {
    for (int i = 1; i <= N; ++i) {
      if (parent[i][j] != -1) {
        parent[i][j + 1] = parent[parent[i][j]][j];
      }
    }
  }

  scanf("%d", &M);
  for (int m = 0; m < M; ++m) {
    int x, y;
    scanf("%d%d", &x, &y);

    if (depth[x] < depth[y]) {
      int tmp = x;
      x = y;
      y = tmp;
    }

    int diff = depth[x] - depth[y];
    int j = 0;
    while (diff) {
      if (diff % 2) x = parent[x][j];
      diff /= 2;
      ++j;
    }

    if (x != y) {
      for (int j = 17; j >= 0; --j) {
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