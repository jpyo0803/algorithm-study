//
// Candy Game
// Link: https://www.acmicpc.net/problem/3085
//

#include <cstdio>

using namespace std;

constexpr int kMax = 50;
int N;

int d[2][2] = {{0, 1}, {1, 0}};

bool InRange(int r, int c) { return r >= 0 && r < N && c >= 0 && c < N; }
int Max(int x, int y) { return x > y ? x : y; }
void swap(char& x, char& y) {
  char tmp = x;
  x = y;
  y = tmp;
}

struct Point {
  Point(int _x, int _y) : x(_x), y(_y) {}
  int x, y;
};

struct Board {
  char m[kMax][kMax];
};

int CountMax(Board& b, int r, int c, int dir) {
  int local_max = 0;
  char prev_char;
  int count = 0;
  int tr = dir ? r : 0;
  int tc = dir ? 0 : c;

  while (InRange(tr, tc)) {
      if (prev_char != b.m[tr][tc]) {
        local_max = Max(local_max, count);
        count = 1;
        prev_char = b.m[tr][tc];
      } else {
        count++;
      }
      tr += d[(dir + 1) % 2][0];
      tc += d[(dir + 1) % 2][1];
  }
  local_max = Max(local_max, count);
  return local_max;
 }

int Check(Board b, int r, int c) {
  int local_max = 0;
  for (int i = 0; i < 2; i++) {
    int nr = r + d[i][0];
    int nc = c + d[i][1];

    if (InRange(nr, nc)) {
      swap(b.m[r][c], b.m[nr][nc]);
      local_max = Max(local_max, CountMax(b, r, c, i));
      local_max = Max(local_max, CountMax(b, nr, nc, i));
      swap(b.m[r][c], b.m[nr][nc]);
      local_max = Max(local_max, CountMax(b, r, c, i));
    }
  }
  return local_max;
}

int main() {
  Board b;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    char row[kMax + 1];
    scanf("%s", row);
    for (int j = 0; j < N; j++) {
      b.m[i][j] = row[j];
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans = Max(ans, Check(b, i, j));
    }
  }

  printf("%d\n", ans);

  return 0;
}