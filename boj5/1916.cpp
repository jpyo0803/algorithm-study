//
// 최소비용 구하기
// Link: https://www.acmicpc.net/problem/1916
//

#include <cstdio>
#include <queue>
#include <vector>

constexpr int kMaxV = 1000;
constexpr int INF = 987654321;

using namespace std;

int N, M, S, E, u, v, w;

vector<pair<int, int>> adj[kMaxV + 1];
int Dijkstra(int s, int e) { 
  vector<int> dist(N + 1, INF);
  dist[s] = 0;

  priority_queue<pair<int, int>> pq;
  pq.emplace(0, s);
  while (!pq.empty()) {
    int cost = -pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (dist[u] < cost) continue;

    for (auto& e : adj[u]) {
      int v = e.second;
      int next_dist = cost + e.first;
      if (next_dist < dist[v]) {
        dist[v] = next_dist;
        pq.emplace(-next_dist, v);
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
  return 0;
}