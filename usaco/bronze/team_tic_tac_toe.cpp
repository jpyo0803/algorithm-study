// Team Tic Tac Toe (Bronze)
// https://www.acmicpc.net/problem/15763

#include <bits/stdc++.h>

using namespace std;

char board[3][3];

int IsOurs(char target, const vector<char>& team) {
  for (int i = 0; i < team.size(); ++i) {
    if (target == team[i]) return i;
  }
  return -1;
}

bool IsWin(const vector<char>& team) {
  bool ok;
  int sum;
  int used[2]{};
  
  // check row
  for (int i = 0; i < 3; ++i) {
    used[0] = used[1] = 0;
    for (int j = 0; j < 3; ++j) {
      int ret = IsOurs(board[i][j], team);
      if (ret != -1) used[ret]++;
    }
    ok = true;
    sum = 0;
    for (int j = 0; j < team.size(); ++j) {
      sum += used[j];
      if (used[j] == 0) ok = false;
    }
    if (ok && sum == 3) return true;
  }

  // check col
  for (int j = 0; j < 3; ++j) {
    used[0] = used[1] = 0;
    for (int i = 0; i < 3; ++i) {
      int ret = IsOurs(board[i][j], team);
      if (ret != -1) used[ret]++;
    }
    ok = true;
    sum = 0;
    for (int i = 0; i < team.size(); ++i) {
      sum += used[i];
      if (used[i] == 0) ok = false;
    }
    if (ok && sum == 3) return true;
  }

  // check diag, top left to bottom right
  used[0] = used[1] = 0;
  for (int i = 0; i < 3; ++i) {
    int ret = IsOurs(board[i][i], team);
    if (ret != -1) used[ret]++;
  }    
  ok = true;
  sum = 0;
  for (int i = 0; i < team.size(); ++i) {
    sum += used[i];
    if (used[i] == 0) ok = false;
  }
  if (ok && sum == 3) return true;

  used[0] = used[1] = 0;
  for (int i = 0; i < 3; ++i) {
    int ret = IsOurs(board[i][2 - i], team);
    if (ret != -1) used[ret]++;
  }  
  ok = true;
  sum = 0;
  for (int i = 0; i < team.size(); ++i) {
    sum += used[i];
    if (used[i] == 0) ok = false;
  }
  if (ok && sum == 3) return true;

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> board[i][j];
    }
  }

  int ans1 = 0;
  for (char i = 'A'; i <= 'Z'; ++i) {
    vector<char> team = {i};
    if (IsWin(team)) ans1++;
  }
  int ans2 = 0;
  for (char i = 'A'; i <= 'Z' - 1; ++i) {
    for (char j = i + 1; j <= 'Z'; ++j) {
      vector<char> team = {i, j};
      if (IsWin(team)) ans2++;
    }
  }

  cout << ans1 << "\n" << ans2 << "\n";

  return 0;
}