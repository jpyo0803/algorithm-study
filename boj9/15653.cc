// 구슬 탈출 4
// https://www.acmicpc.net/problem/15653

#include <stdio.h>

#include <queue>
#include <utility>

using namespace std;

constexpr char kSpace = '.';
constexpr char kObstacle = '#';
constexpr char kHole = 'O';
constexpr char kRed = 'R';
constexpr char kBlue = 'B';

struct Info {
  pair<int, int> rl;
  pair<int, int> bl;
  int num_rot = 0;
};

int N, M;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

char board[11][11];
bool visited[11][11][11][11];

int Solve(const Info& info) {
  int ans = 987654321;
  queue<Info> que;
  que.push(info);

  while (!que.empty()) {
    auto now = que.front();
    que.pop();
    if (ans < now.num_rot) continue;

    for (int dir = 0; dir < 4; ++dir) {
      bool red_first;
      if (dir == 0) {
        red_first = now.rl.second > now.bl.second;
      } else if (dir == 1) {
        red_first = now.rl.first > now.bl.first;
      } else if (dir == 2) {
        red_first = now.rl.first < now.bl.first;
      } else {
        red_first = now.rl.second < now.bl.second;
      }

      pair<int, int> first = red_first ? now.rl : now.bl;
      pair<int, int> second = !red_first ? now.rl : now.bl;

      int fr = first.first, fc = first.second;

      bool red_done = false, blue_done = false;
      bool first_done = false;

      int move = 0;
      while (true) {
        int nr = fr + d[dir][0];
        int nc = fc + d[dir][1];

        if (board[nr][nc] != kSpace ||
            (nr == second.first && nc == second.second)) {
          if (board[nr][nc] == kHole) {
            first_done = true;
            if (red_first)
              red_done = true;
            else
              blue_done = true;
          }
          break;
        } else {
          fr = nr;
          fc = nc;
          ++move;
        }
      }

      first.first = fr;
      first.second = fc;

      int sr = second.first;
      int sc = second.second;

      while (true) {
        int nr = sr + d[dir][0];
        int nc = sc + d[dir][1];

        if (board[nr][nc] != kSpace || (!first_done && nr == fr && nc == fc)) {
          if (board[nr][nc] == kHole) {
            if (!red_first)
              red_done = true;
            else
              blue_done = true;
          }
          break;
        } else {
          sr = nr;
          sc = nc;
          ++move;
        }
      }

      second.first = sr;
      second.second = sc;

      if (blue_done) continue;
      if (red_done) {
        ans = now.num_rot + 1 < ans ? now.num_rot + 1 : ans;
        continue;
      }
      if (!red_done && !blue_done && move > 0) {
        Info next;
        if (red_first) {
          next.rl = first;
          next.bl = second;
        } else {
          next.rl = second;
          next.bl = first;
        }
        next.num_rot = now.num_rot + 1;

        if (visited[next.rl.first][next.rl.second][next.bl.first]
                   [next.bl.second])
          continue;
        visited[next.rl.first][next.rl.second][next.bl.first][next.bl.second] =
            true;
        que.push(next);
      }
    }
  }

  return ans == 987654321 ? -1 : ans;
}

char line[12];

int main() {
  scanf("%d%d", &N, &M);

  Info info;
  for (int i = 0; i < N; ++i) {
    scanf("%s", line);
    for (int j = 0; j < M; ++j) {
      if (line[j] == kBlue) {
        info.bl = make_pair(i, j);
        board[i][j] = kSpace;
      } else if (line[j] == kRed) {
        info.rl = make_pair(i, j);
        board[i][j] = kSpace;
      } else {
        board[i][j] = line[j];
      }
    }
  }

  printf("%d\n", Solve(info));

  return 0;
}