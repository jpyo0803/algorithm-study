//
// Maximum Flow
// Link: https://www.acmicpc.net/problem/6086
// Comment : When same edge appears again its weight needs to be added
//

#include <cstdio>
#include <queue>

using namespace std;

constexpr int kMaxSize = 52;
constexpr int INF = 987654321;
int N, F;
char a, b;
int capacity[kMaxSize][kMaxSize];
int flow[kMaxSize][kMaxSize];
int parent[kMaxSize];

int Ford_Fulkerson(int source, int sink) {
  int max_flow = 0;

  while (true) {
    for (int i = 0; i < kMaxSize; i++) parent[i] = -1;

    queue<int> que;
    que.push(source);
    while (!que.empty() && parent[sink] == -1) {
      int here = que.front();
      que.pop();

      for (int there = 0; there < kMaxSize; there++) {
        if (capacity[here][there] - flow[here][there] > 0 &&
            parent[there] == -1) {
          parent[there] = here;
          que.push(there);
        }
      }
    }
    if (parent[sink] == -1) break;

    int min_flow = INF;
    for (int i = sink; i != source; i = parent[i]) {
      int residual = capacity[parent[i]][i] - flow[parent[i]][i];
      min_flow = min_flow > residual ? residual : min_flow;
    }

    for (int i = sink; i != source; i = parent[i]) {
      flow[parent[i]][i] += min_flow;
      flow[i][parent[i]] -= min_flow;
    }

    max_flow += min_flow;
  }
  return max_flow;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf(" %c %c %d", &a, &b, &F);
    int na, nb;
    if (a >= 'A' && a <= 'Z')
      na = a - 'A';
    else
      na = a - 'a' + 26;
    if (b >= 'A' && b <= 'Z')
      nb = b - 'A';
    else
      nb = b - 'a' + 26;
    capacity[na][nb] += F;
    capacity[nb][na] += F;
  }

  printf("%d\n", Ford_Fulkerson('A' - 'A', 'Z' - 'A'));
  return 0;
}
