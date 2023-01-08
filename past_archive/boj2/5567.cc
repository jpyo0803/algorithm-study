//
// Wedding
// Problem: https://www.acmicpc.net/problem/5567
//

#include <cstdio>
#include <vector>

using namespace std;
const int MAX{500};
int N, M, a, b;
vector<int> relation[MAX + 1];
int level[MAX + 1];

int solve() {
  vector<int> frontier, next;
  frontier.push_back(1);

  int num_invited{0};
  int curr_level = 1;
  level[1] = curr_level;
  while (!frontier.empty()) {
    next.clear();
    for (auto u : frontier) {
      for (auto v : relation[u]) {
        if (level[v] == 0) {
          level[v] = curr_level;
          num_invited += 1;
          next.push_back(v);
        }
      }
    }
    curr_level += 1;
    if (curr_level == 3) {
      return num_invited;
    }
    swap(frontier, next);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    relation[a].push_back(b);
    relation[b].push_back(a);
  }

  printf("%d", solve());

  return 0;
}
