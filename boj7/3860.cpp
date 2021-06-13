// 할로윈 묘지
// https://www.acmicpc.net/problem/3860

#include <stdio.h>

constexpr int kInf = 987654321;

int W, H, G, E;

struct Point {
  int type, x, y, t;
};

Point map[30][30];
int dist[30][30];

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool InRange(int x, int y) { return x >= 0 && x < W && y >= 0 && y < H; }

void Solve() {
  for (int x = 0; x < W; x++) {
    for (int y = 0; y < H; y++) {
      dist[x][y] = kInf;
    }
  }
  dist[0][0] = 0;

  bool updated;
  for (int i = 0; i < W * H; i++) {
    updated = false;
    for (int x = 0; x < W; x++) {
      for (int y = 0; y < H; y++) {
        if (x == W - 1 && y == H - 1) continue;
        if (dist[x][y] == kInf || map[x][y].type == 1)
          continue;  // dont start if type == 1

        if (map[x][y].type == 2) {  // ghost hole
          int nx = map[x][y].x;
          int ny = map[x][y].y;
          if (!InRange(nx, ny) || map[nx][ny].type == 1)
            continue;  // just in case

          int next_cost = dist[x][y] + map[x][y].t;
          if (next_cost < dist[nx][ny]) {
            dist[nx][ny] = next_cost;
            updated = true;
          }
        } else {  // check all around
          for (int j = 0; j < 4; j++) {
            int nx = x + d[j][0];
            int ny = y + d[j][1];

            if (!InRange(nx, ny) || map[nx][ny].type == 1)
              continue;  // dont relax if next type == 1
            int next_cost = dist[x][y] + 1;
            if (next_cost < dist[nx][ny]) {
              dist[nx][ny] = next_cost;
              updated = true;
            }
          }
        }
      }
    }
    if (!updated) break;
  }

  if (updated)
    printf("Never\n");
  else if (dist[W - 1][H - 1] != kInf)
    printf("%d\n", dist[W - 1][H - 1]);
  else
    printf("Impossible\n");
}

int main() {
  scanf("%d%d", &W, &H);
  while (W != 0 && H != 0) {
    for (int x = 0; x < W; x++) {
      for (int y = 0; y < H; y++) {
        map[x][y].type = 0;
      }
    }

    scanf("%d", &G);
    for (int g = 0; g < G; g++) {
      int x, y;
      scanf("%d%d", &x, &y);
      map[x][y].type = 1;
    }

    scanf("%d", &E);
    for (int e = 0; e < E; e++) {
      int x1, y1, x2, y2, t;
      scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &t);
      map[x1][y1].type = 2;
      map[x1][y1].x = x2;
      map[x1][y1].y = y2;
      map[x1][y1].t = t;
    }

    Solve();

    scanf("%d%d", &W, &H);
  }

  return 0;
}
