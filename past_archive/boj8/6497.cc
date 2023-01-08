// 전력난
// https://www.acmicpc.net/problem/6497

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
  int u, v, z;
  Edge(int _u, int _v, int _z) : u(_u), v(_v), z(_z) {}
};

int M, N, x, y, z;
vector<Edge> edges;
int parent[200000];

bool Comparator(const Edge& a, const Edge& b) { return a.z < b.z; }

int GetRoot(int now) {
  if (parent[now] == now) return now;
  return parent[now] = GetRoot(parent[now]);
}

int Solve() {
  int sum = 0;
  int save = 0;
  for (auto& edge : edges) {
    int u = edge.u, v = edge.v, dist = edge.z;
    sum += dist;

    int pu = GetRoot(u);
    int pv = GetRoot(v);

    if (pu != pv) {
      parent[pu] = pv;
      save += dist;
    }
  }
  return sum - save;
}

int main() {
  edges.reserve(200000);

  while (true) {
    scanf("%d%d", &M, &N);
    if (M == 0 && N == 0) break;
    if (M > 0 && N == 0) {
      printf("0\n");
      continue;
    }

    for (int m = 0; m < M; m++) parent[m] = m;
    edges.clear();

    for (int n = 0; n < N; n++) {
      scanf("%d%d%d", &x, &y, &z);
      edges.emplace_back(x, y, z);
    }

    sort(edges.begin(), edges.end(), Comparator);
    printf("%d\n", Solve());
  }
  return 0;
}
