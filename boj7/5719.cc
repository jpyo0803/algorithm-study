// 거의 최단 경로
// https://www.acmicpc.net/problem/5719

#include <stdio.h>

#include <queue>
#include <vector>

using namespace std;

constexpr int kInf = 987654321;

int N, M, S, D, U, V, P;

int dist[500];
int w[500][500];

vector<int> adj[500];
vector<int> paths[500];
bool visited[500];

void EliminatePath(int now) {
  if (now == S || visited[now]) return;
  visited[now] = true;

  for (auto parent : paths[now]) {
    if (w[parent][now] == -1) continue;
    w[parent][now] = -1;
    EliminatePath(parent);
  }
}

int Solve() {
  for (int i = 0; i < N; i++) dist[i] = kInf;
  dist[S] = 0;
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, S);

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (dist[u] < cost) continue;

    for (auto v : adj[u]) {
      if (w[u][v] == -1) continue;

      int next_dist = cost + w[u][v];
      if (next_dist <= dist[v]) {
        if (next_dist < dist[v]) {
          dist[v] = next_dist;
          pq.emplace(-next_dist, v);

          paths[v].clear();
          paths[v].push_back(u);
        } else {
          paths[v].push_back(u);
        }
      }
    }
  }

  if (dist[D] == kInf) return -1;

  EliminatePath(D);

  while (!pq.empty()) pq.pop();
  for (int i = 0; i < N; i++) dist[i] = kInf;
  dist[S] = 0;
  pq.emplace(0, S);

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (dist[u] < cost) continue;

    for (auto v : adj[u]) {
      if (w[u][v] == -1) continue;

      int next_dist = cost + w[u][v];
      if (next_dist < dist[v]) {
        dist[v] = next_dist;
        pq.emplace(-next_dist, v);
      }
    }
  }

  return dist[D] == kInf ? -1 : dist[D];
}

int main() {
  scanf("%d%d", &N, &M);
  while (N != 0 && M != 0) {
    for (int i = 0; i < N; i++) {
      adj[i].clear();
      paths[i].clear();
      visited[i] = false;
      for (int j = 0; j < N; j++) {
        w[i][j] = -1;
      }
    }
    scanf("%d%d", &S, &D);
    for (int m = 0; m < M; m++) {
      scanf("%d%d%d", &U, &V, &P);
      adj[U].push_back(V);
      w[U][V] = P;
    }

    int min_dist = Solve();
    printf("%d\n", min_dist);

    scanf("%d%d", &N, &M);
  }
  return 0;
}
