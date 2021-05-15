// 경사로
// https://www.acmicpc.net/problem/14890

#include <stdio.h>

int N, L;
int map[100][100];
bool used[100][100][2];

int Solve() {
  int ans = 0;

  for (int i = 0; i < N; i++) {
    bool row_valid = true, col_valid = true;
    for (int j = 0; j < N - 1; j++) {
      int diff;
      if (row_valid) {
        diff = map[i][j + 1] - map[i][j];
        if (diff < -1 || diff > 1) {
          row_valid = false;
        } else if (diff == -1) {  // Down
          if (j + L >= N) {
            row_valid = false;
          } else {
            int level = map[i][j + 1];
            int valid_count = 0;
            for (int k = j + 1; k <= j + L; k++) {
              if (!used[i][k][0] && map[i][k] == level) {
                used[i][k][0] = true;
                valid_count++;
              }
            }
            if (valid_count != L) row_valid = false;
          }
        } else if (diff == 1) {  // Up
          if (j - L + 1 < 0) {
            row_valid = false;
          } else {
            int level = map[i][j];
            int valid_count = 0;
            for (int k = j - L + 1; k <= j; k++) {
              if (!used[i][k][0] && map[i][k] == level) {
                used[i][k][0] = true;
                valid_count++;
              }
            }
            if (valid_count != L) row_valid = false;
          }
        }
      }

      if (col_valid) {
        diff = map[j + 1][i] - map[j][i];
        if (diff < -1 || diff > 1) {
          col_valid = false;
        } else if (diff == -1) {  // Down
          if (j + L >= N) {
            col_valid = false;
          } else {
            int level = map[j + 1][i];
            int valid_count = 0;
            for (int k = j + 1; k <= j + L; k++) {
              if (!used[k][i][1] && map[k][i] == level) {
                used[k][i][1] = true;
                valid_count++;
              }
            }
            if (valid_count != L) col_valid = false;
          }
        } else if (diff == 1) {  // Up
          if (j - L + 1 < 0) {
            col_valid = false;
          } else {
            int level = map[j][i];
            int valid_count = 0;
            for (int k = j - L + 1; k <= j; k++) {
              if (!used[k][i][1] && map[k][i] == level) {
                used[k][i][1] = true;
                valid_count++;
              }
            }
            if (valid_count != L) col_valid = false;
          }
        }
      }
    }
    if (row_valid) ans++;
    if (col_valid) ans++;
  }
  return ans;
}

int main() {
  scanf("%d%d", &N, &L);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &map[i][j]);
    }
  }

  printf("%d\n", Solve());

  return 0;
}
