//
// The number of islands
// Problem: https://www.acmicpc.net/problem/4963
//

#include <iostream>
#include <vector>

int d[8][2] = {{1, 0},   {-1, 0}, {0, 1},  {0, -1},
               {-1, -1}, {1, 1},  {-1, 1}, {1, -1}};

using namespace std;
const int MAX{50};
int w, h;
bool map[MAX][MAX];
bool visited[MAX][MAX];

void bfs(int i, int j) {
  vector<pair<int, int>> frontier, next;
  frontier.emplace_back(i, j);

  while (!frontier.empty()) {
    next.clear();
    for (auto u : frontier) {
      for (int k = 0; k < 8; k++) {
        int vi{u.first + d[k][0]}, vj{u.second + d[k][1]};
        if (vi >= 0 && vi < h && vj >= 0 && vj < w && map[vi][vj] &&
            !visited[vi][vj]) {
          visited[vi][vj] = true;
          next.emplace_back(vi, vj);
        }
      }
    }
    swap(frontier, next);
  }
}

int solve(int w, int h) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      visited[i][j] = false;
    }
  }
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (map[i][j] && !visited[i][j]) {
        visited[i][j] = true;
        bfs(i, j);
        ans += 1;
      }
    }
  }
  return ans;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> w >> h;
  while (!(w == 0 && h == 0)) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> map[i][j];
      }
    }
    cout << solve(w, h) << endl;

    cin >> w >> h;
  }
  return 0;
}
