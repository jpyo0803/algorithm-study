//
// TSP 2 (Brute-force, Did not use DP)
// Link: https://www.acmicpc.net/problem/10971
//

#include <cstdio>
#include <vector>

using namespace std;

int Min(int x, int y) { return x < y ? x : y; }

constexpr int kMax = 10;
constexpr int INF = 987654321;
int N;

int dist[kMax][kMax];
bool visited[kMax];

int DFS(vector<int>& path, int length_upto_now) {
  if (path.size() == N) {
    int u = path[path.size() - 1];
    if (dist[u][0]) return length_upto_now + dist[u][0];
    return INF;
  }

  int ret = INF;
  for (int v = 0; v < N; v++) {
    int u = path[path.size() - 1];
    if (dist[u][v] && !visited[v]) {
      path.push_back(v);
      visited[v] = true;
      ret = Min(ret, DFS(path, length_upto_now + dist[u][v]));
      visited[v] = false;
      path.pop_back();
    }
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &dist[i][j]);
    }
  }

  vector<int> path = {0};
  visited[0] = true;
  printf("%d\n", DFS(path, 0));

  return 0;
}
