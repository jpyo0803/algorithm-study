// 배열에서 이동
// https://www.acmicpc.net/problem/1981

#include <bits/stdc++.h>

using namespace std;

int n;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int arr[105][105];
bool visited[105][105];
int glob_min = 200;
int glob_max = 0;

bool Solve(int low, int high) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      visited[i][j] = false;
    }
  }

  queue<pair<int, int>> que;
  que.emplace(0, 0);
  visited[0][0] = true;

  while (que.size()) {
    int ux = que.front().first;
    int uy = que.front().second;
    que.pop();

    if (arr[ux][uy] < low || arr[ux][uy] > high) continue;
    if (ux == n - 1 && uy == n - 1) return true;

    for (int i = 0; i < 4; ++i) {
      int vx = ux + dx[i];
      int vy = uy + dy[i];
      if (vx < 0 || vx >= n || vy < 0 || vy >= n) continue;
      if (visited[vx][vy] == false) {
        visited[vx][vy] = true;
        que.emplace(vx, vy);
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      glob_min = min(glob_min, arr[i][j]);
      glob_max = max(glob_max, arr[i][j]);
    }
  }

  int ans = -1;
  int low = 0;
  int high = 200;

  while (low <= high) {
    int mid = (low + high) / 2;
    bool ok = false;

    for (int i = glob_min; i <= glob_max; ++i) {
      ok |= Solve(i, i + mid);
      if (ok) break;
    }
    if (ok) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << ans << "\n";

  return 0;
}