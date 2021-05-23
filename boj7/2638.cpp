// 치즈
// https://www.acmicpc.net/problem/2638

#include <stdio.h>

#include <stack>

using namespace std;

int N, M, num_cheese;
int map[100][100];
bool visited[100][100];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Point {
  int i, j;
  Point(int _i, int _j) : i(_i), j(_j) {}
};

bool InRange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; }

int Solve(const int n, const int m) {
  int time = 0;

  while (num_cheese > 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        visited[i][j] = false;
      }
    }

    stack<Point> stk;
    stk.emplace(0, 0);
    visited[0][0] = true;
    while (!stk.empty()) {
      Point now = stk.top();
      stk.pop();
      for (int k = 0; k < 4; k++) {
        Point next(now.i + d[k][0], now.j + d[k][1]);
        if (!InRange(next.i, next.j)) continue;
        if (map[next.i][next.j] > 0)
          map[next.i][next.j]++;
        else if (!visited[next.i][next.j]) {
          visited[next.i][next.j] = true;
          stk.emplace(next.i, next.j);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map[i][j] > 2) {
          map[i][j] = 0;
          num_cheese--;
        } else if (map[i][j] > 1) {
          map[i][j] = 1;
        }
      }
    }
    time++;
  }
  return time;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j] == 1) num_cheese++;
    }
  }

  printf("%d\n", Solve(N, M));

  return 0;
}
