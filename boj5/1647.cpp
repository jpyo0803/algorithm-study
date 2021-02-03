//
// 도시분할계획
// Link: https://www.acmicpc.net/problem/1647
//

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct PathInfo {
  PathInfo(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
  int u, v, w;
};

int N, M;
vector<PathInfo> path_infos;
vector<int> parent;

bool Compare(const PathInfo& x, const PathInfo& y) { return x.w < y.w; }

int GetParent(int child) {
  if (parent[child] == -1) return child;
  parent[child] = GetParent(parent[child]);
  return parent[child];
}

int main() {
  scanf("%d%d", &N, &M);
  path_infos.reserve(M);
  parent = vector<int>(N + 1, -1);
  for (int m = 0; m < M; m++) {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    path_infos.emplace_back(A, B, C);
  }

  sort(path_infos.begin(), path_infos.end(), Compare);

  int edge_count = 0;
  int weight_sum = 0;
  for (auto& path_info : path_infos) {
    int parent_u = GetParent(path_info.u);
    int parent_v = GetParent(path_info.v);
    if (parent_u != parent_v) {
      int smaller = parent_u < parent_v ? parent_u : parent_v;
      int bigger = parent_u + parent_v - smaller;
      parent[bigger] = smaller;
      weight_sum += path_info.w;
      if (++edge_count == N - 2) break;
    }
  }
  printf("%d\n", weight_sum);

  return 0;
}
