//
// チーズ
// Problem: https://www.acmicpc.net/problem/5558
//

#include <cstdio>
#include <vector>

using namespace std;
const int MAX{1000};
int H, W, N, sr, sc;
char map[MAX][MAX];
bool visited[MAX][MAX];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int er, ec;
int bfs(int sr, int sc, char e) {
  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      visited[r][c] = false;
    }
  }

  vector<pair<int, int>> frontier, next;
  frontier.emplace_back(sr, sc);
  visited[sr][sc] = true;

  int level{0};
  while (!frontier.empty()) {
    next.clear();
    for (auto u : frontier) {
      if (map[u.first][u.second] == e) {
        er = u.first;
        ec = u.second;
        return level;
      }
      for (int i = 0; i < 4; i++) {
        int nr{u.first + d[i][0]};
        int nc{u.second + d[i][1]};
        if (nr >= 0 && nr < H && nc >= 0 && nc < W && map[nr][nc] != 'X' &&
            !visited[nr][nc]) {
          visited[nr][nc] = true;
          next.emplace_back(nr, nc);
        }
      }
    }
    swap(frontier, next);
    level += 1;
  }
}

int main() {
  scanf("%d%d%d", &H, &W, &N);
  char str[MAX + 1];
  for (int r = 0; r < H; r++) {
    scanf("%s", str);
    for (int c = 0; c < W; c++) {
      map[r][c] = str[c];
      if (map[r][c] == 'S') {
        sr = r;
        sc = c;
      }
    }
  }

  int ans{0};
  for (int i = 1; i <= N; i++) {
    ans += bfs(sr, sc, i + '0');
    sr = er;
    sc = ec;
  }
  printf("%d", ans);
  return 0;
}