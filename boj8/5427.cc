// 불
// https://www.acmicpc.net/problem/5427

#include <stdio.h>

#include <vector>

using namespace std;

constexpr char kSpace = '.';
constexpr char kWall = '#';
constexpr char kSanggeun = '@';
constexpr char kFire = '*';

int T, W, H;
char map[1010][1010];
char line[1010];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool InRange(int w, int h) { return w >= 0 && w < W && h >= 0 && h < H; }

vector<pair<int, int>> fire_frontier, fire_next;
vector<pair<int, int>> sanggeun_frontier, sanggeun_next;

void Solve() {
  int level = 0;
  bool escaped = false;
  while (!escaped && !sanggeun_frontier.empty()) {
    fire_next.clear();
    for (auto& fire : fire_frontier) {
      for (int i = 0; i < 4; ++i) {
        int nfh = fire.first + d[i][0];
        int nfw = fire.second + d[i][1];
        if (!InRange(nfw, nfh)) continue;
        if (map[nfh][nfw] == kSpace || map[nfh][nfw] == kSanggeun) {
          fire_next.emplace_back(nfh, nfw);
          map[nfh][nfw] = kFire;
        }
      }
    }
    swap(fire_frontier, fire_next);

    sanggeun_next.clear();
    for (auto& sanggeun : sanggeun_frontier) {
      if (sanggeun.first == 0 || sanggeun.first == H - 1 ||
          sanggeun.second == 0 || sanggeun.second == W - 1) {
        escaped = true;
        break;
      }
      for (int i = 0; i < 4; ++i) {
        int nsh = sanggeun.first + d[i][0];
        int nsw = sanggeun.second + d[i][1];
        if (!InRange(nsw, nsh)) continue;
        if (map[nsh][nsw] == kSpace) {
          sanggeun_next.emplace_back(nsh, nsw);
          map[nsh][nsw] = kSanggeun;
        }
      }
    }
    swap(sanggeun_frontier, sanggeun_next);
    ++level;
  }
  if (!escaped) {
    printf("IMPOSSIBLE\n");
  } else {
    printf("%d\n", level);
  }
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    fire_frontier.clear();
    fire_next.clear();
    sanggeun_frontier.clear();
    sanggeun_next.clear();
    scanf("%d%d", &W, &H);

    for (int h = 0; h < H; ++h) {
      scanf("%s", line);
      for (int w = 0; w < W; ++w) {
        map[h][w] = line[w];
        if (map[h][w] == kSanggeun) {
          sanggeun_frontier.emplace_back(h, w);
        } else if (map[h][w] == kFire) {
          fire_frontier.emplace_back(h, w);
        }
      }
    }
    Solve();
  }
  return 0;
}