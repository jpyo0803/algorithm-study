// Chessboard and Queens
// https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>

using namespace std;

char board[8][8];

bool col[8];
bool diag1[15];
bool diag2[15];

long long ans = 0;

void Search(int i) {
  if (i == 8) {
    ++ans;
    return;
  }

  for (int j = 0; j < 8; ++j) {
    if (board[i][j] == '*') continue;
    if (col[j]) continue;
    if (diag1[i + j]) continue;
    if (diag2[8 - j + i - 1]) continue;
    col[j] = diag1[i + j] = diag2[8 - j + i - 1] = true;
    Search(i + 1);
    col[j] = diag1[i + j] = diag2[8 - j + i - 1] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cin >> board[i][j];
    }
  }

  Search(0);

  cout << ans << "\n";

  return 0;
}