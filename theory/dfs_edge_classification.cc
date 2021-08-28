/*
 This dfs example can explore every graph
 and also classifies tree edge, forward edge, backward edge, and cross edge
 Time complexity = O(V + E) directed
                 = O(V + 2E) undirected
*/

#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> nodes[7];
int parent[7];
int depth[7];
int groups[7];

int time_complexity = 0;

void dfs_visit(int cn, int group, int ith) {
  printf("%d-th : %d\n", ith, cn);
  time_complexity++;
  for (auto nn : nodes[cn]) {
    time_complexity++;
    if (parent[nn] == -1) {
      printf("%d -> %d : tree edge\n", cn, nn);
      parent[nn] = cn;
      depth[nn] = ith + 1;
      groups[nn] = group;
      dfs_visit(nn, group, ith + 1);
    } else {
      if (groups[cn] == groups[nn]) {
        if (depth[cn] < depth[nn]) {
          printf("%d -> %d : forward edge\n", cn, nn);
        } else {
          printf("%d -> %d : backward edge\n", cn, nn);
        }
      } else {
        printf("%d -> %d : cross edge\n", cn, nn);
      }
    }
  }
}
void dfs() {
  for (int i = 1; i < 7; i++) parent[i] = -1;
  int group = 1;
  for (int i = 1; i < 7; i++) {
    if (parent[i] == -1) {
      parent[i] = 0;
      depth[i] = 1;
      groups[i] = group;
      dfs_visit(i, group++, 1);
    }
  }
}

int main() {
  int E = 8;                     // # edges
  vector<pair<int, int>> edges;  // u -> v
  edges.emplace_back(1, 2);
  edges.emplace_back(2, 5);
  edges.emplace_back(5, 4);
  edges.emplace_back(4, 2);
  edges.emplace_back(3, 6);
  edges.emplace_back(6, 6);
  edges.emplace_back(1, 4);
  edges.emplace_back(3, 5);

  for (auto edge : edges) {
    nodes[edge.first].push_back(edge.second);
    nodes[edge.second].push_back(edge.first);  // if undirected graph
  }

  dfs();
  printf("Time complexity = %d\n", time_complexity);
  return 0;
}