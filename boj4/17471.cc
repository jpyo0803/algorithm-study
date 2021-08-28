//
// Gerrymandering
// Link: https://www.acmicpc.net/problem/17471
//

#include <cstdio>
#include <queue>

using namespace std;

int Min(int x, int y) { return x < y ? x : y; }
int Abs(int x) { return x < 0 ? -x : x; }

constexpr int INF = 987654321;
constexpr int kMax = 11;

int N, e, u;
int population[kMax];
bool adj[kMax][kMax];
bool assignment[kMax];

int Check(int start_node) {
  bool visited[N];
  for (int i = 1; i <= N; i++) visited[i] = false;
  queue<int> que;
  que.push(start_node);
  visited[start_node] = true;

  int node_visited = 1;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int u = 1; u <= N; u++) {
      if (adj[v][u] && !visited[u] && assignment[start_node] == assignment[u]) {
        visited[u] = true;
        que.push(u);
        node_visited++;
      }
    }
  }
  return node_visited;
}

int DFS(bool assignment[], int depth) {
  if (depth == N + 1) {
    int group1_count = 0, group2_count = 0;
    int population1 = 0, population2 = 0;
    int first_group1 = -1, first_group2 = -1;
    for (int i = 1; i <= N; i++) {
      if (assignment[i]) {
        group1_count++;
        population1 += population[i];
        if (first_group1 == -1) first_group1 = i;
      } else {
        group2_count++;
        population2 += population[i];
        if (first_group2 == -1) first_group2 = i;
      }
    }
    if (group1_count == 0 || group2_count == 0) return INF;
    if (Check(first_group1) != group1_count) return INF;
    if (Check(first_group2) != group2_count) return INF;
    return Abs(population1 - population2);
  }

  int ret = INF;
  for (int i = 0; i < 2; i++) {
    assignment[depth] = i != 0;
    ret = Min(ret, DFS(assignment, depth + 1));
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &population[i]);
  for (int v = 1; v <= N; v++) {
    scanf("%d", &e);
    for (int i = 0; i < e; i++) {
      scanf("%d", &u);
      adj[u][v] = adj[v][u] = true;
    }
  }

  int ans = DFS(assignment, 1);
  printf("%d\n", ans == INF ? -1 : ans);
  return 0;
}