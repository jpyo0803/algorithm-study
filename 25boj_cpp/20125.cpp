// 쿠키의 신체 측정
// https://www.acmicpc.net/problem/20125

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<char>> map(n, vector<char>(n));

  int heart_x, heart_y;
  heart_x = -1;

  for (int i = 0; i < n; ++i) { // x
    for (int j = 0; j < n; ++j) { // y
      cin >> map[i][j];
      if (map[i][j] == '*' && heart_x == -1) {
        heart_x = i + 1; 
        heart_y = j;
      }
    }
  }

  int left_arm_len = 0;
  int right_arm_len = 0;
  int waist_len = 0;
  int left_leg_len = 0;
  int right_leg_len = 0;

  int j = heart_y - 1;
  while (j >= 0 && map[heart_x][j] == '*') {
    left_arm_len++;
    j--;
  }
  j = heart_y + 1;
  while (j < n && map[heart_x][j] == '*') {
    right_arm_len++;
    j++;
  }

  int i = heart_x + 1;
  while (i < n && map[i][heart_y] == '*') {
    waist_len++;
    i++;
  }

  i = heart_x + waist_len + 1;
  while (i < n && map[i][heart_y - 1] == '*') {
    left_leg_len++;
    i++;
  }
  
  i = heart_x + waist_len + 1;
  while (i < n && map[i][heart_y + 1] == '*') {
    right_leg_len++;
    i++;
  }

  cout << heart_x + 1 << " " << heart_y + 1 << "\n";
  cout << left_arm_len << " " << right_arm_len << " " << waist_len << " " << left_leg_len << " " << right_leg_len << "\n";

  return 0;
}