//
// 뱀과 사다리 게임
// Link: https://www.acmicpc.net/problem/16928
// Comment: DP로는 왜 안풀릴까...
//

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

constexpr int kMax = 100;
constexpr int INF = 987654321;

struct Info {
  Info(int _x, int _step) : x(_x), step(_step) {}
  int x, step;
};

int N, M;

bool visited[kMax + 1];
int jump[kMax + 1];

int BFS(int start, int end) {
  vector<Info> frontier, next;

  frontier.emplace_back(start, 0);
  visited[start] = true;
  while (!frontier.empty()) {
    next.clear();
    for (auto& u : frontier) {
      if (u.x == 100) {
        return u.step;
      }
      for (int i = 1; i <= 6; i++) {
        int v = u.x + i;
        if (v < 101 && !visited[v]) {
          if (jump[v]) {
            visited[v] = true;
            v = jump[v];
          }
          visited[v] = true;
          next.emplace_back(v, u.step + 1);
        }
      }
    }
    swap(frontier, next);
  }
  return -1;  // should not reach
}

int main() {
  scanf("%d%d", &N, &M);
  int u, v;
  for (int i = 0; i < N + M; i++) {
    scanf("%d%d", &u, &v);
    jump[u] = v;
  }

  printf("%d\n", BFS(1, 100));
  return 0;
}
