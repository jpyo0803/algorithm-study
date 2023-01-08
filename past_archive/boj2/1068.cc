//
// Tree
// Problem: https://www.acmicpc.net/problem/1068
//

#include <cstdio>
#include <vector>

using namespace std;
const int MAX{50};
int N, R, u;
vector<int> adj_list[MAX];
vector<int> root_nodes;
bool valid_node[MAX];

int num_leaf{0};
void dfs(int curr) {
  int valid_count{0};
  for (auto v : adj_list[curr]) {
    if (!valid_node[v]) {
      dfs(v);
      valid_count += 1;
    }
  }
  if (valid_count == 0) {
    num_leaf += 1;
  }
}

int main() {
  scanf("%d", &N);
  for (int v = 0; v < N; v++) {
    scanf("%d", &u);
    if (u != -1) {
      adj_list[u].push_back(v);
    } else {
      root_nodes.push_back(v);
    }
  }
  scanf("%d", &R);
  valid_node[R] = true;

  for (auto root : root_nodes) {
    if (!valid_node[root]) {
      dfs(root);
    }
  }
  printf("%d", num_leaf);
  return 0;
}
