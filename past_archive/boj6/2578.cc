//
// 빙고
// Link: https://www.acmicpc.net/problem/2578
//

#include <stdio.h>

#include <map>
#include <utility>

using namespace std;

int table[5][5];
bool cross_out[26];
map<int, pair<int, int>> nmap;

int CheckDiagonalRightDown(int r, int c) {
  if (r != c) return 0;
  for (int i = 0; i < 5; i++) {
    if (!cross_out[table[i][i]]) return 0;
  }
  return 1;
}

int CheckDiagonalLeftUp(int r, int c) {
  if (r + c != 4) return 0;
  for (int i = 0; i < 5; i++) {
    if (!cross_out[table[i][4 - i]]) return 0;
  }
  return 1;
}

int CheckHorizontal(int r) {
  for (int c = 0; c < 5; c++) {
    if (!cross_out[table[r][c]]) return 0;
  }
  return 1;
}

int CheckVertical(int c) {
  for (int r = 0; r < 5; r++) {
    if (!cross_out[table[r][c]]) return 0;
  }
  return 1;
}

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &table[i][j]);
      nmap[table[i][j]] = make_pair(i, j);
    }
  }

  int bingo_count = 0;
  int number_said = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int number;
      scanf("%d", &number);
      number_said++;
      cross_out[number] = true;

      int r = nmap[number].first;
      int c = nmap[number].second;
      bingo_count += CheckDiagonalRightDown(r, c);
      bingo_count += CheckDiagonalLeftUp(r, c);
      bingo_count += CheckHorizontal(r);
      bingo_count += CheckVertical(c);

      if (bingo_count >= 3) {
        printf("%d\n", number_said);
        return 0;
      }
    }
  }

  return 0;
}
