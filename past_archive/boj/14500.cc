//
// Tetromino
// https://www.acmicpc.net/problem/14500
// Comment: I did it very very brute force way, redo it later
//

#include <iostream>

using namespace std;

const int MAX_SIZE{500};
int N, M;
int grid[MAX_SIZE][MAX_SIZE];

int d[5][4][2] = {{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
                  {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
                  {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
                  {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
                  {{0, 0}, {0, 1}, {0, 2}, {1, 1}}};

bool range_check(int i, int j) { return (i >= 0 && i < N && j >= 0 && j < M); }

int operation(int curr_d[][2], int i, int j) {
  int res = 0;
  for (int k = 0; k < 4; k++) {
    int ni{i + curr_d[k][0]};
    int nj{j + curr_d[k][1]};

    if (range_check(ni, nj)) {
      res += grid[ni][nj];
    } else {
      return 0;
    }
  }
  return res;
}

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

void vertical_flip(int curr_d[][2]) {
  for (int i = 0; i < 4; i++) curr_d[i][1] = -curr_d[i][1];
}

void rotate_ccw(int curr_d[][2]) {
  for (int i = 0; i < 4; i++) {
    swap(curr_d[i][0], curr_d[i][1]);
    curr_d[i][0] = -curr_d[i][0];
  }
}

int solve() {
  int curr_d[4][2];
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int l = 0; l < 5; l++) {
        for (int ii = 0; ii < 4; ii++) {
          for (int jj = 0; jj < 2; jj++) {
            curr_d[ii][jj] = d[l][ii][jj];
          }
        }
        int k = 0;
        do {
          ans = max(ans, operation(curr_d, i, j));
          rotate_ccw(curr_d);
          k++;
        } while (k < 4);
        for (int ii = 0; ii < 4; ii++) {
          for (int jj = 0; jj < 2; jj++) {
            curr_d[ii][jj] = d[l][ii][jj];
          }
        }
        vertical_flip(curr_d);
        k = 0;
        do {
          ans = max(ans, operation(curr_d, i, j));
          rotate_ccw(curr_d);
          k++;
        } while (k < 4);
      }
    }
  }
  return ans;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }

  cout << solve();
  return 0;
}