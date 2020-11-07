//
// 스도미노쿠
// Link: https://www.acmicpc.net/problem/4574
//

#include <cstdio>
#include <cstring>

struct Board {
  int data[9][9];
};

Board b;

bool finish;
int question_number = 1;

int d[2][2] = {{0, 1}, {1, 0}};
bool tile_used[10][10];

bool InRange(int r, int c) { return r >= 0 && r < 9 && c >= 0 && c < 9; }

bool IsValid(const Board& b, int r, int c, int v) {
  for (int i = 0; i < 9; i++) {
    if (b.data[r][i] == v) return false;
  }

  for (int i = 0; i < 9; i++) {
    if (b.data[i][c] == v) return false;
  }

  int oi = (r / 3) * 3;
  int oj = (c / 3) * 3;
  for (int i = oi; i < oi + 3; i++) {
    for (int j = oj; j < oj + 3; j++) {
      if (b.data[i][j] == v) return false;
    }
  }
  return true;
}

void BackTracking() {
  if (finish) return;
  int r = -1, c = -1;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (b.data[i][j] != 0) continue;
      r = i;
      c = j;
      break;
    }
    if (r != -1) break;
  }
  
  if (r == -1) {
    printf("Puzzle %d\n", question_number++);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        printf("%d", b.data[i][j]);
      }
      printf("\n");
    }
    finish = true;
    return;
  }

  for (int i = 1; i <= 9; i++) {
    b.data[r][c] = 0;
    if (!IsValid(b, r, c, i)) continue;
    b.data[r][c] = i;

    for (int j = 1; j <= 9; j++) {
      if (i == j) continue;
      if (tile_used[i][j] || tile_used[j][i]) continue;
      for (int k = 0; k < 2; k++) {
        int ar = r + d[k][0];
        int ac = c + d[k][1];
        if (!InRange(ar, ac)) continue;
        if (b.data[ar][ac] != 0) continue;
        if (!IsValid(b, ar, ac, j)) continue;
        b.data[ar][ac] = j;
        tile_used[i][j] = tile_used[j][i] = true;
        BackTracking();
        tile_used[i][j] = tile_used[j][i] = false;
        b.data[ar][ac] = 0;
      }
    }
    b.data[r][c] = 0;
  }
}

int main() {
  int N;
  scanf("%d", &N);
  while (N != 0) {
    int u, v;
    char LU[3];
    char LV[3];

    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        tile_used[i][j] = false;
      }
    }

    memset(b.data, 0, sizeof(b.data));

    for (int i = 0; i < N; i++) {
      scanf("%d%s%d%s", &u, LU, &v, LV);
      b.data[LU[0] - 'A'][LU[1] - '1'] = u;
      b.data[LV[0] - 'A'][LV[1] - '1'] = v;
      tile_used[u][v] = tile_used[v][u] = true;
    }

    for (int i = 1; i <= 9; i++) {
      scanf("%s", LU);
      b.data[LU[0] - 'A'][LU[1] - '1'] = i;
    }
    finish = false;
    BackTracking();

    scanf("%d", &N);
  }
}
