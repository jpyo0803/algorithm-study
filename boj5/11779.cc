//
// 최소비용 구하기2
// Link: https://www.acmicpc.net/problem/11779
//

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

constexpr int kMaxN = 1000;
constexpr int INF = 987654321;

int N, M, u, v, w, S, E;

vector<pair<int, int>> adj[kMaxN + 1];
int p[kMaxN + 1];

void PrintPath(int current, int depth) {
  if (current == S) {
    printf("%d\n", depth);
    printf("%d ", S);
    return;
  }

  PrintPath(p[current], depth + 1);
  printf("%d ", current);
}

int Dijkstra(int s, int e) {
  vector<int> dist(N + 1, INF);
  dist[s] = 0;

  priority_queue<pair<int, int>> pq;
  pq.emplace(0, s);
  p[s] = -1;

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (dist[u] < cost) continue;
    for (auto& e : adj[u]) {
      int v = e.second;
      int next_cost = e.first + cost;
      if (next_cost < dist[v]) {
        pq.emplace(-next_cost, v);
        dist[v] = next_cost;
        p[v] = u;
      }
    }
  }

  return dist[e];
}

int main() {
  scanf("%d%d", &N, &M);
  for (int m = 0; m < M; m++) {
    scanf("%d%d%d", &u, &v, &w);
    adj[u].emplace_back(w, v);
  }
  scanf("%d%d", &S, &E);

  printf("%d\n", Dijkstra(S, E));
  PrintPath(E, 1);
  printf("\n");
  return 0;
}