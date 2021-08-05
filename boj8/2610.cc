// 회의준비
// https://www.acmicpc.net/problem/2610

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

constexpr int kInf = 987654321;

int N, M, a, b;

int dist[101][101];
vector<int> groups[101];
int num_groups = 0;

bool visited[101];

int Min(int x, int y) { return x < y ? x : y; }

void Dfs(int u, int group_number) {
  visited[u] = true;
  groups[group_number].push_back(u);
  for (int v = 1; v <= N; v++) {
    if (u == v || visited[v] || dist[u][v] == kInf) continue;
    Dfs(v, group_number);
  }
}

void Solve() {
  for (int k = 1; k <= N; k++) {
    for (int u = 1; u <= N; u++) {
      if (dist[u][k] == kInf || dist[u][k] == 0) continue;
      for (int v = 1; v <= N; v++) {
        dist[u][v] = Min(dist[u][v], dist[u][k] + dist[k][v]);
      }
    }
  }

  for (int u = 1; u <= N; u++) {
    if (!visited[u]) {
      num_groups++;
      Dfs(u, num_groups);
    }
  }

  printf("%d\n", num_groups);
  vector<int> reps;
  for (int i = 1; i <= num_groups; i++) {
    int global_min = kInf;
    int rep;
    for (auto u : groups[i]) {
      int local_max = 0;
      for (auto v : groups[i]) {
        if (local_max < dist[u][v]) local_max = dist[u][v];
      }
      if (local_max < global_min) {
        global_min = local_max;
        rep = u;
      }
    }
    reps.push_back(rep);
  }
  std::sort(reps.begin(), reps.end());
  for (auto rep : reps) printf("%d\n", rep);
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      dist[i][j] = kInf;
    }
  }
  for (int m = 0; m < M; m++) {
    scanf("%d%d", &a, &b);
    dist[a][b] = dist[b][a] = 1;
  }

  Solve();
  return 0;
}
