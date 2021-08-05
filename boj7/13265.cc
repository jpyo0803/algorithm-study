// 색칠하기
// https://www.acmicpc.net/problem/13265

#include <stdio.h>

#include <vector>

using namespace std;

int T, N, M, x, y;

bool connected[1001][1001];
vector<int> G[1001];
int check[1001];

bool Solve(int u, int prev_color) {
  if (check[u] > 0) {
    if (check[u] == prev_color) return false;
    return true;
  }

  int color = (prev_color == 1) ? 2 : 1;

  check[u] = color;

  bool ret = true;
  for (auto v : G[u]) {
    ret &= Solve(v, color);
  }
  return ret;
}

bool Solve() {
  bool ret = true;
  for (int i = 1; i <= N; i++) {
    if (check[i] == 0) {
      ret &= Solve(i, 1);
    }
  }
  return ret;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        connected[i][j] = false;
      }
      G[i].clear();
      check[i] = 0;
    }
    for (int i = 0; i < M; i++) {
      scanf("%d%d", &x, &y);
      if (!connected[x][y]) {
        connected[x][y] = connected[y][x] = true;
        G[x].push_back(y);
        G[y].push_back(x);
      }
    }
    printf("%s\n", Solve() ? "possible" : "impossible");
  }

  return 0;
}
