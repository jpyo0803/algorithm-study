// 움직이는 미로 탈출
// https://www.acmicpc.net/problem/16954

#include <bits/stdc++.h>

using namespace std;

constexpr int kN = 8;

char arr[kN][kN];
int visited[kN][kN];

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void UpdateMap() {
  for (int i = kN - 1; i >= 0; --i) {
    for (int j = 0; j < kN; ++j) {
      if (arr[i][j] == '#') {
        arr[i][j] = '.';
        if (i + 1 < kN) {
          arr[i + 1][j] = '#';
        } 
      }
    }
  }
}

bool OutOfRange(int x, int y) {
  return x < 0 || x >= kN || y < 0 || y >= kN;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < kN; ++i) {
    for (int j = 0; j < kN; ++j) {
      cin >> arr[i][j];
    }
  }

  vector<pair<int, int>> frontier;
  frontier.emplace_back(kN - 1, 0);
  visited[kN - 1][0] = 0;
  
  int step = 1;

  bool ans = false;
  while (frontier.size() && ans == false) {
    vector<pair<int, int>> tmp;

    for (auto e : frontier) {
      int ux = e.first;
      int uy = e.second;
      // cout << ux << " / " << uy << endl;

      if (arr[ux][uy] == '#') continue;

      if (ux == 0 && uy == kN - 1) {
        ans = true;
      }

      for (int i = 0; i < 9; ++i) {
        int vx = ux + dx[i];
        int vy = uy + dy[i];

        if (OutOfRange(vx, vy)) continue;
        if (arr[vx][vy] == '#') continue;
        if (visited[vx][vy] >= step) continue;
        visited[vx][vy] = step;
        tmp.emplace_back(vx, vy);
      }
    }

    UpdateMap();

    frontier.swap(tmp);
    step++;
  }

  cout << ans << "\n";

  return 0;
}