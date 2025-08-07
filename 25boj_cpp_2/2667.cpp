// 단지번호붙이기
// https://www.acmicpc.net/problem/2667

#include <bits/stdc++.h>

using namespace std;

int n;
char arr[30][30];
bool visited[30][30];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int Dfs(int x, int y) {
  int ret = 1;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
    if (arr[nx][ny] == '0') continue;
    if (visited[nx][ny]) continue;
    visited[nx][ny] = true;
    ret += Dfs(nx, ny);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (visited[i][j]) continue;
      if (arr[i][j] == '0') continue;
      visited[i][j] = true;
      ans.push_back(Dfs(i, j));
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (auto e : ans) cout << e << "\n";

  return 0;
}