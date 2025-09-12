// 숫자판 점프
// https://www.acmicpc.net/problem/2210

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int arr[5][5];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

set<int> ans;

void Solve(int x, int y, int v, int d) {
  if (d == 5) {
    ans.insert(v);
    return;
  }

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
    int nv = v * 10 + arr[nx][ny];
    Solve(nx, ny, nv, d + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      Solve(i, j, arr[i][j], 0);
    }
  }

  cout << ans.size() << "\n";

  return 0;
}