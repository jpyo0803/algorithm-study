//
// 야구
// Link: https://www.acmicpc.net/problem/17281
//

#include <cassert>
#include <cstdio>


int Max(int x, int y) { return x > y ? x : y; }

int N;
int A[50][9];
int order[9];
bool used[9];
int max_score = 0;

void DFS(int depth) {
  if (depth == 9) {
    int score = 0;
    int who = 0;
    for (int i = 0; i < N; i++) {
      bool lu[4];
      for (int i = 1; i < 4; i++) lu[i] = false;
      lu[0] = true;
      int out = 0;
      while (out < 3) {
        if (A[i][order[who]] == 0) {
          out++;
        } else {
          for (int j = 3; j >= 0; j--) {
            if (lu[j]) {
              int os = j + A[i][order[who]];
              if (os > 3)
                score++;
              else
                lu[os] = true;
              if (j != 0) lu[j] = false;
            }
          }
        }
        who++;
        who %= 9;
      }
    }
    max_score = Max(max_score, score);
    return;
  }

  if (depth == 3)
    DFS(depth + 1);
  else {
    for (int i = 0; i < 9; i++) {
      if (!used[i]) {
        order[depth] = i;
        used[i] = true;
        DFS(depth + 1);
        used[i] = false;
      }
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  used[0] = true;
  order[3] = 0;
  DFS(0);
  printf("%d\n", max_score);
  return 0;
}