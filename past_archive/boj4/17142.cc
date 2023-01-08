//
// Research Center 3
// Link: https://www.acmicpc.net/problem/17142
//

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Point {
  Point(int _r, int _c) : r(_r), c(_c) {}
  int r, c;
};

constexpr int kMax = 50;
constexpr int INF = 987654321;

int N, M;
int space_count = 0;

int Min(int x, int y) { return x < y ? x : y; }
int Max(int x, int y) { return x > y ? x : y; }
bool InRange(int r, int c) { return r >= 0 && r < N && c >= 0 && c < N; }

int map[kMax][kMax];
int moves[kMax][kMax];

vector<Point> candidates;
vector<int> selected;

int BFS(vector<Point>& virus_loc) {
  queue<Point> que;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      moves[i][j] = -1;
    }
  }
  for (auto& virus : virus_loc) {
    moves[virus.r][virus.c] = 0;
    que.push(virus);
  }

  int space_fill_count = M;
  int local_ans = 0;
  while (!que.empty()) {
    auto cp = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nr = cp.r + d[i][0];
      int nc = cp.c + d[i][1];
      if (InRange(nr, nc) && moves[nr][nc] == -1) {
        if (map[nr][nc] == 0 || map[nr][nc] == 2) {
          moves[nr][nc] = moves[cp.r][cp.c] + 1;
          if (map[nr][nc] == 0) {
            local_ans = Max(local_ans, moves[nr][nc]);
          }
          que.emplace(nr, nc);
          space_fill_count++;
        }
      }
    }
  }

  if (space_fill_count == space_count) return local_ans;
  return INF;
}

int DFS(vector<int>& selected) {
  if (selected.size() == M) {
    vector<Point> virus_loc;
    for (int i = 0; i < selected.size(); i++) {
      virus_loc.push_back(candidates[selected[i]]);
    }
    return BFS(virus_loc);
  }

  int ret = INF;
  int begin = selected.size() ? selected[selected.size() - 1] + 1 : 0;
  for (int i = begin; i < candidates.size(); i++) {
    selected.push_back(i);
    ret = Min(ret, DFS(selected));
    selected.pop_back();
  }
  return ret;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j] == 2) {
        candidates.emplace_back(i, j);
        space_count++;
      } else if (map[i][j] == 0) {
        space_count++;
      }
    }
  }

  int ans = DFS(selected);
  printf("%d\n", ans == INF ? -1 : ans);

  return 0;
}
