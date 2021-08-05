// 책 구매하기
// https://www.acmicpc.net/problem/11405

#include <stdio.h>

#include <queue>
#include <vector>

using namespace std;

constexpr int kSource = 0;
constexpr int kSink = 201;
constexpr int kInf = 987654321;

int N, M, c;
int capacity[202][202];
int flow[202][202];
int cost[202][202];
int parent[202];
int dist[202];

vector<int> adj[202];  // 0 = source, 201 = sink

int Min(int x, int y) { return x < y ? x : y; }

int Solve() {
  int total_cost = 0;

  while (true) {
    for (int i = 1; i <= M; i++) {
      parent[i] = -1;
      dist[i] = kInf;
    }
    for (int i = 1; i <= N; i++) {
      parent[100 + i] = -1;
      dist[100 + i] = kInf;
    }
    parent[kSink] = -1;
    parent[kSource] = kSource;
    dist[kSink] = kInf;

    queue<int> que;
    que.push(kSource);
    dist[kSource] = 0;

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (auto v : adj[u]) {
        int new_dist = dist[u] + cost[u][v];

        if (capacity[u][v] - flow[u][v] > 0 && new_dist < dist[v]) {
          dist[v] = new_dist;
          que.push(v);
          parent[v] = u;
        }
      }
    }
    if (parent[kSink] == -1) break;

    int amount = kInf;
    for (int p = kSink; p != kSource; p = parent[p]) {
      amount = Min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
    }

    for (int p = kSink; p != kSource; p = parent[p]) {
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount;
      total_cost += amount * cost[parent[p]][p];
    }
  }

  return total_cost;
}

int main() {
  scanf("%d%d", &N, &M);

  for (int i = 1; i <= N; ++i) {
    adj[100 + i].push_back(kSink);
    scanf("%d", &c);
    capacity[100 + i][kSink] = c;
  }

  for (int i = 1; i <= M; ++i) {
    adj[kSource].push_back(i);
    scanf("%d", &c);
    capacity[kSource][i] = c;
  }

  for (int u = 1; u <= M; ++u) {
    for (int v = 1; v <= N; ++v) {
      adj[u].push_back(100 + v);
      adj[100 + v].push_back(u);
      capacity[u][100 + v] = kInf;
      scanf("%d", &c);
      cost[u][100 + v] = c;
      cost[100 + v][u] = -c;
    }
  }

  printf("%d\n", Solve());

  return 0;
}
