//
// City Roundtrip 2
// Link: https://www.acmicpc.net/problem/2316
//

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

constexpr int kMaxCity = 400;
constexpr int INF = 987654321;
int N, P, u, v;

vector<int> adj[kMaxCity * 2 + 1];
int capacity[kMaxCity * 2 + 1][kMaxCity * 2 + 1];
int flow[kMaxCity * 2 + 1][kMaxCity * 2 + 1];
int parent[kMaxCity * 2 + 1];

int Ford_Fulkerson(int source, int sink) {
  int max_flow = 0;

  while (true) {
    for (int i = 1; i <= N; i++) parent[i] = parent[i + kMaxCity] = -1;

    queue<int> que;
    que.push(source);
    parent[source] = source;
    flow[source][source + kMaxCity] = flow[sink - kMaxCity][sink] = 0;
    while (!que.empty() && parent[sink] == -1) {
      int here = que.front();
      que.pop();
      for (auto& there : adj[here]) {
        if (capacity[here][there] - flow[here][there] > 0 &&
            parent[there] == -1) {
          parent[there] = here;
          que.push(there);
        }
      }
    }
    if (parent[sink] == -1) break;

    for (int i = sink; i != source; i = parent[i]) {
      flow[parent[i]][i] = 1;
      flow[i][parent[i]] = -1;
    }
    max_flow += 1;
  }
  return max_flow;
}

int main() {
  scanf("%d%d", &N, &P);
  for (int i = 1; i <= N; i++) {
    adj[i].push_back(kMaxCity + i);
    capacity[i][kMaxCity + i] = 1;
  }
  for (int i = 0; i < P; i++) {
    scanf("%d%d", &u, &v);
    adj[u + kMaxCity].push_back(v);
    adj[v].push_back(u + kMaxCity);
    adj[v + kMaxCity].push_back(u);
    adj[u].push_back(v + kMaxCity);
    capacity[u + kMaxCity][v] = capacity[v + kMaxCity][u] = 1;
  }

  printf("%d\n", Ford_Fulkerson(1, kMaxCity + 2));
  return 0;
}