// 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> arr;
int visited[1005][1005][2]; // not broken, broken 

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;  

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      visited[i][j][0] = visited[i][j][1] = -1;
    }
  }

  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    arr.push_back(x);
  }

  queue<pair<pair<int, int>, bool>> que;
  que.emplace(pair<int, int>(0, 0), false);
  visited[0][0][0] = 1;
  
  while (que.empty() == false) {
    auto x = que.front();
    que.pop();

    int ux = x.first.first;
    int uy = x.first.second;

    bool has_broken = x.second;

    for (int i = 0; i < 4; ++i) {
      int vx = ux + dx[i];
      int vy = uy + dy[i];

      if (vx < 0 || vx >= n || vy < 0 || vy >= m) continue;
      if (visited[vx][vy][has_broken] != -1) continue;
      if (arr[vx][vy] == '1') {
        // if wall and has not broken yet
        if (has_broken == false) {
          que.emplace(pair<int, int>(vx, vy), true);
          visited[vx][vy][true] = visited[ux][uy][false] + 1;
        }
      } else {
        que.emplace(pair<int, int>(vx, vy), has_broken);
        visited[vx][vy][has_broken] = visited[ux][uy][has_broken] + 1;
      }
    }
  }

  int ans = -1;

  int c1 = visited[n - 1][m - 1][0];
  int c2 = visited[n - 1][m - 1][1];
  if (c1 != -1 && c2 != -1) {
    ans = min(c1, c2);
  } else if (c1 != -1) {
    ans = c1;
  } else if (c2 != -1) {
    ans = c2;
  }

  cout << ans << "\n";

  return 0;
}