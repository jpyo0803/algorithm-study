// 소문난 칠공주 
// https://www.acmicpc.net/problem/1941

#include <bits/stdc++.h>

#define ll long long

using namespace std;

char arr[5][5];

vector<pair<int, int>> chosen;
int chosen_arr[5][5];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int Solve(int i) {
  if (chosen.size() == 7) {
    int scnt = 0, ycnt = 0;
    bool ok = true;

    bool vis[8]{};
    queue<pair<int, int>> que;
    que.push(chosen[0]);
    vis[1] = true;
    if (arr[chosen[0].first][chosen[0].second] == 'S') scnt++;
    else ycnt++;

    while (que.size()) {
      int x, y;
      tie(x, y) = que.front();
      que.pop();

      for (int j = 0; j < 4; ++j) {
        int nx = x + dx[j], ny = y + dy[j];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (chosen_arr[nx][ny] == 0) continue;
        if (vis[chosen_arr[nx][ny]]) continue;
        vis[chosen_arr[nx][ny]] = true;
        que.push(chosen[chosen_arr[nx][ny] - 1]);
        if (arr[nx][ny] == 'S') scnt++;
        else ycnt++;
      }
    }
    // cout << scnt << " / " << ycnt << endl;
    if (scnt + ycnt != 7 || scnt < ycnt) ok = false;
    return ok ? 1 : 0;
  }
  if (i >= 25) return 0;

  int x = i / 5, y = i % 5;
  int ret = 0;

  chosen.emplace_back(x, y);
  chosen_arr[x][y] = chosen.size();
  ret += Solve(i + 1);
  chosen_arr[x][y] = 0;
  chosen.pop_back();
  ret += Solve(i + 1);
  return ret;
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

  cout << Solve(0) << "\n";

  return 0;
}