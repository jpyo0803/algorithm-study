// 불!
// https://www.acmicpc.net/problem/4179

#include <bits/stdc++.h>

using namespace std;

int r, c;
char arr[1005][1005];
int visited[1005][1005];  // also record distance

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void PrintDist() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << "------------------------" << endl;
}

bool CheckRange(int i, int j) {
  if (i < 0 || i >= r || j < 0 || j >= c) return false;
  return true;
}

bool IsWall(int i, int j) { return arr[i][j] == '#'; }

bool IsFire(int i, int j) { return arr[i][j] == 'F'; }

bool IsVisited(int i, int j) { return visited[i][j] != -1; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c;

  vector<pair<int, int>> jihoon_frontier, fire_frontier;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      visited[i][j] = -1;

      cin >> arr[i][j];
      if (arr[i][j] == 'J') {
        jihoon_frontier.emplace_back(i, j);
        visited[i][j] = 0;
      }
      if (arr[i][j] == 'F') {
        fire_frontier.emplace_back(i, j);
      }
    }
  }

  // Only one Jihoon is possible
  assert(jihoon_frontier.size() == 1);
  // while fire can be many

  // BFS, update fire first and then jihoon

  bool successful = false;

  pair<int, int> ans;
  while (jihoon_frontier.empty() == false) {
    // algo stops when jihoon can no longer move, alg stops and return false
    // if johoon can reach out of range, alg stops and returns true

    vector<pair<int, int>> jihoon_tmp, fire_tmp;

    for (auto fu : fire_frontier) {
      int ux = fu.first;
      int uy = fu.second;

      for (int i = 0; i < 4; ++i) {
        int vx = ux + dx[i];
        int vy = uy + dy[i];
        // cout << vx << " / " < vy << endl;

        if (CheckRange(vx, vy) == false) continue;
        if (IsWall(vx, vy) || IsFire(vx, vy))
          continue;  // if already fire, do not proceed there
        arr[vx][vy] = 'F';
        fire_tmp.emplace_back(vx, vy);
      }
    }
    // update jihoon first
    for (auto ju : jihoon_frontier) {
      int ux = ju.first;
      int uy = ju.second;

      for (int i = 0; i < 4; ++i) {
        int vx = ux + dx[i];
        int vy = uy + dy[i];

        bool in_range = CheckRange(vx, vy);
        if (in_range == false) {
          // can escape
          successful = true;
          ans = {ux, uy};
          break;
        } else {
          // keep exploring

          if (IsFire(vx, vy) || IsWall(vx, vy)) continue;
          if (IsVisited(vx, vy)) continue;
          visited[vx][vy] = visited[ux][uy] + 1;
          jihoon_tmp.emplace_back(vx, vy);
        }
      }

      if (successful) break;
    }
    if (successful) break;


    // PrintDist();

    jihoon_frontier.swap(jihoon_tmp);
    fire_frontier.swap(fire_tmp);
  }

  // cout << ans.first << " / " << ans.second << endl;

  if (successful)
    cout << visited[ans.first][ans.second] + 1 << "\n";
  else
    cout << "IMPOSSIBLE\n";

  return 0;
}