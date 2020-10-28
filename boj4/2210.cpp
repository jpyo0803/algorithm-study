//
// 숫자판 점프
// Link: https://www.acmicpc.net/problem/2210
//

#include <cstdio>
#include <set>

using namespace std;

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int board[5][5];

set<int> record;

void DFS(int r, int c, int number, int depth) {
  number = number * 10 + board[r][c];
  if (depth == 6) {
    record.insert(number);
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nr = r + d[i][0];
    int nc = c + d[i][1];

    if (nr < 0 || nr > 4 || nc < 0 || nc > 4) continue;
    DFS(nr, nc, number, depth + 1);
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      DFS(i, j, 0, 1);
    }
  }
  printf("%d\n", record.size());
}