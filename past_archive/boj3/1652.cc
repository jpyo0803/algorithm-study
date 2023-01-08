//
// Find a place to lie down
// Problem: https://www.acmicpc.net/problem/1652
//

#include <cstdio>

const int MAX{100};
int N;

char line[MAX + 1];
char map[MAX + 1][MAX + 1];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", line);
    for (int j = 0; j < N; j++) {
      map[i][j] = line[j];
    }
  }

  for (int i = 0; i < N; i++) {
    map[i][N] = map[N][i] = 'X';
  }

  int gh = 0;
  int gv = 0;

  for (int i = 0; i <= N; i++) {
    int lh = 0;
    int lv = 0;
    for (int j = 0; j <= N; j++) {
      if (map[i][j] == 'X') {
        if (lh >= 2) {
          gh += 1;
        }
        lh = 0;
      } else {
        lh += 1;
      }
      if (map[j][i] == 'X') {
        if (lv >= 2) {
          gv += 1;
        }
        lv = 0;
      } else {
        lv += 1;
      }
    }
  }

  printf("%d %d", gh, gv);
  return 0;
}
