// Team Tic Tac Toe (Bronze)
// https://www.acmicpc.net/problem/15763

#include <bits/stdc++.h>

using namespace std;

char board[3][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> board[i][j];
    }
  }
  
  set<char> ans1;
  set<set<char>> ans2;
  // vertical1
  for (int i = 0; i < 3; ++i) {
    set<char> ss;
    for (int j = 0; j < 3; ++j) {
      ss.insert(board[i][j]);
    }
    if (ss.size() == 1) ans1.insert(*ss.begin());
    if (ss.size() == 2) ans2.insert(ss);
  }
  for (int i = 0; i < 3; ++i) {
    set<char> ss;
    for (int j = 0; j < 3; ++j) {
      ss.insert(board[j][i]);
    }
    if (ss.size() == 1) ans1.insert(*ss.begin());
    if (ss.size() == 2) ans2.insert(ss);
  }
  set<char> ss;
  for (int i = 0; i < 3; ++i) {
    ss.insert(board[i][i]);
  }
  if (ss.size() == 1) ans1.insert(*ss.begin());
  if (ss.size() == 2) ans2.insert(ss);

  ss.clear();
  for (int i = 0; i < 3; ++i) {
    ss.insert(board[i][2 - i]);
  }
  if (ss.size() == 1) ans1.insert(*ss.begin());
  if (ss.size() == 2) ans2.insert(ss);

  cout << ans1.size() << "\n" << ans2.size() << "\n";

  return 0;
}