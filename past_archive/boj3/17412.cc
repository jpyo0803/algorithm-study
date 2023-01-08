//
// City Roundtrip
// Link: https://www.acmicpc.net/problem/17412
//

#include <cstdio>
#include <queue>

using namespace std;

constexpr int kMaxCity = 400;
int N, P, u, v;

int capacity[kMaxCity + 1][kMaxCity + 1];
int flow[kMaxCity + 1][kMaxCity + 1];
int parent[kMaxCity + 1];

int Ford_Fulkerson(int source, int sink) {
  int max_flow = 0;

  while (true) {
    for (int i = 1; i <= N; i++) parent[i] = -1;
    queue<int> que;
    que.push(source);
    while (!que.empty() && parent[sink] == -1) {
      int here = que.front();
      que.pop();
      for (int there = 1; there <= N; there++) {
        if (capacity[here][there] - flow[here][there] > 0 &&
            parent[there] == -1) {
          parent[there] = here;
          que.push(there);
        }
      }
    }

    if (parent[sink] == -1) break;

    for (int i = sink; i != source; i = parent[i]) {
      flow[parent[i]][i] += 1;
      flow[i][parent[i]] -= 1;
    }
    max_flow += 1;
  }
  return max_flow;
}
int main() {
  scanf("%d%d", &N, &P);
  for (int i = 0; i < P; i++) {
    scanf("%d%d", &u, &v);
    capacity[u][v] = 1;
  }

  printf("%d\n", Ford_Fulkerson(1, 2));
  return 0;
}