//
// Bridge Building
// Link: https://www.acmicpc.net/problem/2146
//

#include <cstdio>
#include <queue>

struct Point {
  Point(int _r, int _c) : r(_r), c(_c) {}
  int r, c;
};

constexpr int kMax = 100;
int N, e;

using namespace std;

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool map[kMax][kMax];
bool visited[kMax][kMax];
int moves[kMax][kMax];
int group[kMax][kMax];
queue<Point> land;

void BFS1(int x, int y, int group_count) {
  queue<Point> que;
  que.emplace(x, y);
  visited[x][y] = true;
  land.emplace(x, y);
  group[x][y] = group_count;

  while (!que.empty()) {
    auto cp = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nr = cp.r + d[i][0];
      int nc = cp.c + d[i][1];

      if (nr >= 0 && nr < N && nc >= 0 && nc < N && map[nr][nc] &&
          !visited[nr][nc]) {
        visited[nr][nc] = true;
        group[nr][nc] = group_count;
        que.emplace(nr, nc);
        land.emplace(nr, nc);
      }
    }
  }
}

int BFS2(queue<Point>& que) {
  int ans = 987654321;

  while (!que.empty()) {
    auto cp = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nr = cp.r + d[i][0];
      int nc = cp.c + d[i][1];

      if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
        if (visited[nr][nc]) {
          if (group[cp.r][cp.c] != group[nr][nc]) {
            ans = moves[cp.r][cp.c] + moves[nr][nc] < ans
                      ? moves[cp.r][cp.c] + moves[nr][nc]
                      : ans;
          }
        } else {
          visited[nr][nc] = true;
          group[nr][nc] = group[cp.r][cp.c];
          moves[nr][nc] = moves[cp.r][cp.c] + 1;
          que.emplace(nr, nc);
        }
      }
    }
  }

  return ans;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &e);
      map[i][j] = e ? true : false;
    }
  }

  int group_count = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (map[i][j]) {
        if (!visited[i][j]) BFS1(i, j, group_count++);
      }
    }
  }

  printf("%d\n", BFS2(land));

  return 0;
}