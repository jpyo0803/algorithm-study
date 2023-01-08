//
// 2048 (Easy)
// Link: https://www.acmicpc.net/problem/12100
//

#include <cstdio>
using namespace std;
int Max(int x, int y) { return x < y ? y : x; }

constexpr int kMax = 20;
int N;

int board[kMax][kMax];
int tmp_board[kMax][kMax];
int op_seq[5];

void Move2Left(int tmp_board[][kMax]) {
  for (int i = 0; i < N; i++) {
    int idx = 0;
    for (int j = 0; j < N; j++) {
      if (tmp_board[i][j] != 0) {
        int val = tmp_board[i][j];
        for (int k = j + 1; k < N; k++) {
          if (val == tmp_board[i][k]) {
            val *= 2;
            tmp_board[i][k] = 0;
            break;
          } else if (tmp_board[i][k] != 0)
            break;
        }
        tmp_board[i][j] = 0;
        tmp_board[i][idx++] = val;
      }
    }
  }
}
void Move2Right(int tmp_board[][kMax]) {
  for (int i = 0; i < N; i++) {
    int idx = N - 1;
    for (int j = N - 1; j >= 0; j--) {
      if (tmp_board[i][j] != 0) {
        int val = tmp_board[i][j];
        for (int k = j - 1; k >= 0; k--) {
          if (val == tmp_board[i][k]) {
            val *= 2;
            tmp_board[i][k] = 0;
            break;
          } else if (tmp_board[i][k] != 0)
            break;
        }
        tmp_board[i][j] = 0;
        tmp_board[i][idx--] = val;
      }
    }
  }
}
void Move2Top(int tmp_board[][kMax]) {
  for (int j = 0; j < N; j++) {
    int idx = 0;
    for (int i = 0; i < N; i++) {
      if (tmp_board[i][j] != 0) {
        int val = tmp_board[i][j];
        for (int k = i + 1; k < N; k++) {
          if (val == tmp_board[k][j]) {
            val *= 2;
            tmp_board[k][j] = 0;
            break;
          } else if (tmp_board[k][j] != 0)
            break;
        }
        tmp_board[i][j] = 0;
        tmp_board[idx++][j] = val;
      }
    }
  }
}
void Move2Bottom(int tmp_board[][kMax]) {
  for (int j = 0; j < N; j++) {
    int idx = N - 1;
    for (int i = N - 1; i >= 0; i--) {
      if (tmp_board[i][j] != 0) {
        int val = tmp_board[i][j];
        for (int k = i - 1; k >= 0; k--) {
          if (val == tmp_board[k][j]) {
            val *= 2;
            tmp_board[k][j] = 0;
            break;
          } else if (tmp_board[k][j] != 0)
            break;
        }
        tmp_board[i][j] = 0;
        tmp_board[idx--][j] = val;
      }
    }
  }
}

int Solve(int nth) {
  int ret = 0;
  if (nth == 5) {
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        tmp_board[r][c] = board[r][c];
      }
    }
    for (int i = 0; i < nth; i++) {
      if (op_seq[i] == 0)
        Move2Left(tmp_board);
      else if (op_seq[i] == 1)
        Move2Right(tmp_board);
      else if (op_seq[i] == 2)
        Move2Top(tmp_board);
      else if (op_seq[i] == 3)
        Move2Bottom(tmp_board);
    }

    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        ret = Max(ret, tmp_board[r][c]);
      }
    }
    return ret;
  }

  for (int i = 0; i < 4; i++) {
    op_seq[nth] = i;
    ret = Max(ret, Solve(nth + 1));
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  printf("%d\n", Solve(0));
  return 0;
}