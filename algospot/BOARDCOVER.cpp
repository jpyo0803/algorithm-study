//
// BOARDCOVER
// Problem: https://www.algospot.com/judge/problem/read/BOARDCOVER
//

#include <cstdio>
#include <cstring>

constexpr int kMax = 20;

using namespace std;

int C, H, W, empty_count;
bool map[kMax][kMax];

constexpr int kCoverType[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}},
};

bool Check(int r, int c) {
  return r >= 0 && r < H && c >= 0 && c < W && map[r][c];
}

int Solve() {
  int sr = -1, sc = -1;
  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      if (map[r][c]) {
        sr = r;
        sc = c;
        break;
      }
    }
    if (sr != -1) break;
  }

  if (sr == -1) return 1;

  int ret = 0;
  for (int i = 0; i < 4; i++) {
    bool check_pass = true;
    int count = 0;
    for (int j = 0; j < 3; j++) {
      if (!Check(sr + kCoverType[i][j][0], sc + kCoverType[i][j][1])) {
        check_pass = false;
        break;
      }
    }
    if (check_pass) {
      for (int j = 0; j < 3; j++)
        map[sr + kCoverType[i][j][0]][sc + kCoverType[i][j][1]] = false;
      ret += Solve();
      for (int j = 0; j < 3; j++)
        map[sr + kCoverType[i][j][0]][sc + kCoverType[i][j][1]] = true;
    }
  }
  return ret;
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    scanf("%d%d", &H, &W);
    empty_count = 0;
    for (int i = 0; i < H; i++) {
      char row[kMax + 1];
      scanf("%s", row);
      for (int j = 0; j < strlen(row); j++) {
        map[i][j] = (row[j] == '.');
        if (map[i][j]) empty_count++;
      }
    }
    if (empty_count % 3) {
      printf("0\n");
      continue;
    }
    printf("%d\n", Solve());
  }

  return 0;
}