// 벽 부수고 이동하기 4
// https://www.acmicpc.net/problem/16946

#include <bits/stdc++.h>

using namespace std;

int n, m;
char arr[1005][1005];
pair<int, int> brr[1005][1005][4];
bool visited[1005][1005];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OutOfRange(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int Solve(int ux, int uy, vector<tuple<int, int, int>>& locs) {
  int sum = 1;
  for (int i = 0; i < 4; ++i) {
    int vx = ux + dx[i];
    int vy = uy + dy[i];
    if (OutOfRange(vx, vy)) continue;
    if (arr[vx][vy] == '1') {
      locs.emplace_back(vx, vy, i);
    } else {  
      if (visited[vx][vy] == false) {
        visited[vx][vy] = true;
        sum += Solve(vx, vy, locs);
      }
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }

  int gid = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == '1') continue;
      if (visited[i][j]) continue;
      visited[i][j] = true;
           
      vector<tuple<int, int, int>> locs;
      int cnt = Solve(i, j, locs);
      for (auto e : locs) {
        int vx = get<0>(e);
        int vy = get<1>(e);
        int dir = get<2>(e);
        brr[vx][vy][dir] = pair<int, int>(cnt, gid);
      }
      gid++;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == '0') cout << "0";
      else {
        set<int> used;
        int sum = 1;
        for (int k = 0; k < 4; ++k) {
          int cnt = brr[i][j][k].first;
          int gid = brr[i][j][k].second;
          if (gid == 0) continue;
          if (used.find(gid) == used.end()) { // not found
            sum += cnt;
            used.insert(gid);
          }
        }
        cout << (sum % 10);
      }
    }
    cout << "\n";
  }

  return 0;
}