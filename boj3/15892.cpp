//
// Candy Picking Robot
// Link: https://www.acmicpc.net/problem/15892
//

#include <cstdio>
#include <queue>

using namespace std;

constexpr int kMaxRoomNum = 300;
constexpr int INF = 987654321;
int n, m, a, b, c;

int capacity[kMaxRoomNum + 1][kMaxRoomNum + 1];
int flow[kMaxRoomNum + 1][kMaxRoomNum + 1];
int parent[kMaxRoomNum + 1];

int Ford_Fulkerson(int source, int sink) {
  int max_flow = 0;

  while (true) {
    for (int i = 1; i <= n; i++) parent[i] = -1;

    queue<int> que;
    que.push(source);
    while (!que.empty() && parent[sink] == -1) {
      int here = que.front(); que.pop();
      for (int there = 1; there <= n; there++) {
        if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
          parent[there] = here;
          que.push(there);
        }
      }
    }

    if (parent[sink] == -1) break;

    int amount = INF;
    for (int i = sink; i != source; i = parent[i]) {
      int residual = capacity[parent[i]][i] - flow[parent[i]][i];
      amount = residual < amount ? residual : amount;
    }

    for (int i = sink; i != source; i = parent[i]) {
      flow[parent[i]][i] += amount;
      flow[i][parent[i]] -= amount;
    }
    max_flow += amount;
  }
  return max_flow;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    capacity[a][b] += c;
    capacity[b][a] += c;
  }

  printf("%d\n", Ford_Fulkerson(1, n));
  return 0;
}