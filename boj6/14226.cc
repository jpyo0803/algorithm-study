// 이모티콘
// https://www.acmicpc.net/problem/14226

#include <stdio.h>

#include <vector>

using namespace std;

struct Info {
  int n, c;

  Info(int _n, int _c) : n(_n), c(_c) {}
};

bool visited[1001][1001];

int Solve(const int s) {
  vector<Info> frontier, next;
  frontier.emplace_back(1, 0);
  visited[1][0] = true;
  int num_operations = 0;

  while (!frontier.empty()) {
    next.clear();
    for (auto& info : frontier) {
      if (info.n == s) {
        return num_operations;
      }

      if (info.c > 0) {
        int nn = info.n + info.c;
        if (nn < 1001 && !visited[nn][info.c]) {
          visited[nn][info.c] = true;
          next.emplace_back(nn, info.c);
        }
      }

      if (!visited[info.n][info.n]) {
        visited[info.n][info.n] = true;
        next.emplace_back(info.n, info.n);
      }

      int nn = info.n - 1;
      if (nn > 0 && !visited[nn][info.c]) {
        visited[nn][info.c] = true;
        next.emplace_back(nn, info.c);
      }
    }

    num_operations++;
    swap(frontier, next);
  }

  return 0;  // unreachable
}

int main() {
  int S;
  scanf("%d", &S);
  printf("%d\n", Solve(S));
  return 0;
}
