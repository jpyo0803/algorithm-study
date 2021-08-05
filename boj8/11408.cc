// 열혈강호 5
// https://www.acmicpc.net/problem/11408

#include <stdio.h>

#include <queue>
#include <vector>

using namespace std;

constexpr int kSource = 0;
constexpr int kSink = 801;
constexpr int kInf = 987654321;

int N, M;

int capacity[802][802];
int flow[802][802];
int cost[802][802];
int parent[802];
int dist[802];

vector<int> adj[802];

int Min(int x, int y) { return x < y ? x : y; }

void Solve() {
  int total_cost = 0;
  int total_flow = 0;

  while (true) {
    for (int i = 1; i <= N; i++) {
      parent[i] = -1;
      dist[i] = kInf;
    }
    for (int i = 1; i <= M; i++) {
      parent[400 + i] = -1;
      dist[400 + i] = kInf;
    }
    parent[kSink] = -1;
    dist[kSink] = kInf;

    queue<int> que;
    que.push(kSource);
    parent[kSource] = kSource;
    dist[kSource] = 0;

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (auto v : adj[u]) {
        if (capacity[u][v] - flow[u][v] > 0 && dist[u] + cost[u][v] < dist[v]) {
          dist[v] = dist[u] + cost[u][v];
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
    total_flow += amount;
  }

  printf("%d\n%d\n", total_flow, total_cost);
}

int main() {
  scanf("%d%d", &N, &M);

  for (int i = 1; i <= N; ++i) {
    int c;
    scanf("%d", &c);
    capacity[kSource][i] = 1;
    adj[kSource].push_back(i);
    for (int j = 0; j < c; ++j) {
      int k, p;
      scanf("%d%d", &k, &p);

      capacity[i][k + 400] = 1;
      adj[i].push_back(k + 400);
      cost[i][k + 400] = p;

      adj[k + 400].push_back(i);
      cost[k + 400][i] = -p;

      capacity[400 + k][kSink] = 1;
      adj[400 + k].push_back(kSink);
    }
  }

  Solve();

  return 0;
}
