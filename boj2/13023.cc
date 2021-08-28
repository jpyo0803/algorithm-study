//
// ABCDE
// Problem: https://www.acmicpc.net/problem/13023
//

#include <cstdio>
#include <vector>

using namespace std;
const int MAX{2000};
int N, M, a, b;
vector<int> relation[MAX];
bool visited[MAX];

bool dfs(int curr, int depth) {
  if (depth == 5) return true;
  visited[curr] = true;

  bool found{false};
  for (auto v : relation[curr]) {
    if (!visited[v]) {
      if (dfs(v, depth + 1)) {
        found = true;
        break;
      }
    }
  }
  visited[curr] = false;
  return found;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    relation[a].push_back(b);
    relation[b].push_back(a);
  }

  for (int u = 0; u < N; u++) {
    if (dfs(u, 1)) {
      printf("1");
      return 0;
    }
  }
  printf("0");
  return 0;
}
