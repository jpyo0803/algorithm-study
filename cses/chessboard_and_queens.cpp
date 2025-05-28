// Chessboard and Queens
// https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>

using namespace std;

char board[8][8];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cin >> board[i][j];
    }
  }

  vector<int> queens(8);
  for (int i = 0; i < 8; ++i) queens[i] = i;

  int ans = 0;
  do {
    bool ok = true;
    for (int col = 0; col < 8; ++col) {
      int row = queens[col];
      if (board[row][col] == '*') {
        ok = false;
        break;
      }
    }
    if (ok == false) continue;

    ok = true;
    vector<bool> diag1(15, false);
    for (int col = 0; col < 8; ++col) {
      int row = queens[col];
      if (diag1[7 - row + col]) {
        ok = false;
        break;
      }
      diag1[7 - row + col] = true;
    }
    if (ok == false) continue;

    ok = true;
    vector<bool> diag2(15, false);
    for (int col = 0; col < 8; ++col) {
      int row = queens[col];
      if (diag2[row + col]) {
        ok = false;
        break;
      }
      diag2[row + col] = true;
    }
    if (ok == false) continue;

    ans++;
  } while (next_permutation(queens.begin(), queens.end()));

  cout << ans << "\n";
  return 0;
}