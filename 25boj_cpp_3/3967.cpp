// 매직 스타 
// https://www.acmicpc.net/problem/3967

#include <bits/stdc++.h>

#define ll long long

using namespace std;

char arr[5][9];
bool used[256];

/*
           (0, 4)
(1, 1), (1, 3), (1, 5), (1, 7)
        (2, 2), (2, 6)
(3, 1), (3, 3), (3, 5), (3, 7)
            (4, 4) 
*/

bool Check2(int ch1, int ch2, int ch3, int ch4) {
  int sum = (ch1 - 'A' + 1) + (ch2 - 'A' + 1) + (ch3 - 'A' + 1) + (ch4 - 'A' + 1);
  return sum != 26;
}

bool Check(pair<int, int> pos) {
  if (pos == pair<int, int>(1, 7)) {
    if (Check2(arr[1][1], arr[1][3], arr[1][5], arr[1][7])) return false;// ok
  } else if (pos == pair<int, int>(3, 1)) {
    if (Check2(arr[0][4], arr[1][3], arr[2][2], arr[3][1])) return false; // ok
  } else if (pos == pair<int, int>(3, 7)) {
    if (Check2(arr[0][4], arr[1][5], arr[2][6], arr[3][7])) return false; // 
    if (Check2(arr[3][1], arr[3][3], arr[3][5], arr[3][7])) return false;
  } else if (pos == pair<int, int>(4, 4)) {
    if (Check2(arr[1][1], arr[2][2], arr[3][3], arr[4][4])) return false;
    if (Check2(arr[1][7], arr[2][6], arr[3][5], arr[4][4])) return false;
  }
  return true;
}

bool Solve(int i) {
  if (i == 45) return true;

  int x = i / 9;
  int y = i % 9;

  if (arr[x][y] == '.') {
    return Solve(i + 1);
  } else if (arr[x][y] == 'x') {
    for (char ch = 'A'; ch <= 'L'; ++ch) {
      if (used[ch]) continue;
      used[ch] = true;
      arr[x][y] = ch;
      bool ok = Check({x, y});
      if (ok) {
        if (Solve(i + 1)) return true;
      }
      arr[x][y] = 'x';
      used[ch] = false;
    }
  } else {
    bool ok = Check({x, y});
    if (ok) {
      if (Solve(i + 1)) return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 9; ++j) {
      cin >> arr[i][j];
      used[arr[i][j]] = true;
    }
  }


  Solve(0);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 9; ++j) {
      cout << arr[i][j];
    }
    cout << "\n";
  }

  return 0;
}