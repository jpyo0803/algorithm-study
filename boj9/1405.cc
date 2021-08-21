// 미친 로봇
// https://www.acmicpc.net/problem/1405

#include <stdio.h>

int N;
double p[4];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int visited[40][40];

double FindSimplePath(int r, int c, int n, bool is_simple, double rp) {
  if (!is_simple) return 0.0;
  if (n == N) {
    if (visited[r][c] == 0) return rp;
    return 0.0;
  }

  ++visited[r][c];

  bool still_simple = visited[r][c] < 2;

  double ret = 0.0;
  for (int i = 0; i < 4; ++i) {
    int nr = r + d[i][0];
    int nc = c + d[i][1];
    ret += FindSimplePath(nr, nc, n + 1, is_simple && still_simple, rp * p[i]);
  }

  --visited[r][c];
  return ret;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < 4; ++i) {
    int x;
    scanf("%d", &x);
    p[i] = static_cast<double>(x) / 100;
  }
  printf("%.10lf\n", FindSimplePath(20, 20, 0, true, 1.0));
  return 0;
}