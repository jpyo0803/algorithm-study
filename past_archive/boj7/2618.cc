// 경찰차
// https://www.acmicpc.net/problem/2618

#include <stdio.h>

struct Pair {
  int x, y;
};

Pair events[1010];

int N, W;
int cache[1010][1010];
Pair parent[1010][1010];

int Abs(int x) { return x < 0 ? -x : x; }

int distance(int a, int b) {
  return Abs(events[a].x - events[b].x) + Abs(events[a].y - events[b].y);
}

int Solve(int task_a, int task_b) {
  int& ret = cache[task_a][task_b];
  if (ret != 0) return ret;

  int task_next = (task_a < task_b ? task_b : task_a) + 1;
  if (task_next == W + 2) return 0;

  int subret_a = Solve(task_next, task_b) + distance(task_a, task_next);
  int subret_b = Solve(task_a, task_next) + distance(task_b, task_next);

  if (subret_a < subret_b) {
    ret = subret_a;
    parent[task_a][task_b].x = task_next;
    parent[task_a][task_b].y = task_b;
  } else {
    ret = subret_b;
    parent[task_a][task_b].x = task_a;
    parent[task_a][task_b].y = task_next;
  }

  return ret;
}

int main() {
  scanf("%d%d", &N, &W);
  for (int i = 0; i < 1010; i++) {
    for (int j = 0; j < 1010; j++) {
      parent[i][j].x = parent[i][j].y = -1;
    }
  }

  events[0].x = events[0].y = 1;
  events[1].x = events[1].y = N;
  for (int w = 2; w < W + 2; w++) {
    scanf("%d%d", &events[w].x, &events[w].y);
  }

  int total_dist = Solve(0, 1);
  printf("%d\n", total_dist);

  Pair now;
  now.x = 0;
  now.y = 1;
  while (parent[now.x][now.y].x != -1) {
    if (parent[now.x][now.y].x == now.x)
      printf("2\n");
    else
      printf("1\n");
    now = parent[now.x][now.y];
  }
  return 0;
}
