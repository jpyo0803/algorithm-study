// 미네랄 
// https://www.acmicpc.net/problem/2933

/*
  높이는 r - 1부터 1 
*/

#include <bits/stdc++.h>

using namespace std;

int r, c, n;

char arr[105][105];
bool visited[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void PrintArr() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << arr[i][j];
    }
    cout << endl;
  }
  cout << "-------------------------------" << endl;
}

void Solve2(vector<pair<int, int>>& cluster, int x, int y) {
  // Identify cluster
  if (visited[x][y]) return;
  visited[x][y] = true;
  cluster.emplace_back(x, y);

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    if (arr[nx][ny] == '.') continue;
    Solve2(cluster, nx, ny);
  }
}

void Solve(int h, bool is_from_left) {
  int x = r - h;
  int y = is_from_left ? 0 : c - 1;
  // y = horizontal, x = vertical
  // cout << "x : " << h << " / " << is_from_left << endl;

  int ty = -1;
  while (y < c && y >= 0) {
    if (arr[x][y] == 'x') {
      ty = y;
      break;
    }
    if (is_from_left) y += 1;
    else y -= 1;
  }

  if (ty == -1) return;

  arr[x][ty] = '.';

  // l, r, t, b 다 업데이트 필요
  vector<vector<pair<int, int>>> clusters;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      visited[i][j] = false;
    }
  }

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = ty + dy[i];

    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    if (arr[nx][ny] == '.') continue;
    clusters.push_back(vector<pair<int, int>>());
    Solve2(clusters.back(), nx, ny);
    if (clusters.back().empty()) clusters.pop_back();
  }

  // 각 클러스터의 밑면 구하기
  vector<vector<pair<int, int>>> bottom_clusters;
  for (int i = 0; i < clusters.size(); ++i) {
    vector<int> max_x_arr(c, -1);
    for (auto& e : clusters[i]) {
      max_x_arr[e.second] = max(max_x_arr[e.second], e.first); 
    }
    bottom_clusters.push_back(vector<pair<int, int>>());
    for (int j = 0; j < c; ++j) {
      if (max_x_arr[j] == -1) continue;
      bottom_clusters.back().emplace_back(max_x_arr[j], j);
    }
    if (bottom_clusters.back().empty()) bottom_clusters.pop_back();
  }
  // cout << h << ": ";
  // for (auto& bc : bottom_clusters) {
  //   cout << bc.size() << ": ";
  //   for (auto& e : bc) {
  //     cout << "( " << e.first << ", " << e.second << "), ";
  //   }
  //   cout << endl;
  // }
  // cout << endl; 
  //  for (auto& bc : clusters) {
  //   cout << bc.size() << ": ";
  //   for (auto& e : bc) {
  //     cout << "( " << e.first << ", " << e.second << "), ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  assert(clusters.size() == bottom_clusters.size());

  // 각 클러스터에 포함된 원소중 가장 적게 움직이는 원소를 기준으로 내림
  while (true) {
    bool moved = false;
    for (int i = 0; i < bottom_clusters.size(); ++i) {
      bool can_move = true;
      for (int j = 0; j < bottom_clusters[i].size(); ++j) {
        int x = bottom_clusters[i][j].first;
        int y = bottom_clusters[i][j].second;
        if (x + 1 >= r || arr[x + 1][y] != '.') {
          can_move = false;
          break;
        }
      }
      // cout << "can move : " << can_move << endl;
      if (can_move) {
        for (int j = 0; j < bottom_clusters[i].size(); ++j) {
          bottom_clusters[i][j].first++;
        }
        vector<pair<int, int>> next_cluster;
        for (int j = 0; j < clusters[i].size(); ++j) {
          auto xx = clusters[i][j];
          next_cluster.emplace_back(xx.first + 1, xx.second);
        }
        for (auto& e : clusters[i]) arr[e.first][e.second] = '.';
        for (auto& e : next_cluster) arr[e.first][e.second] = 'x';
        clusters[i].swap(next_cluster);
        moved = true;
      }
    }
    if (moved == false) break;
  }
  // PrintArr();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> arr[i][j];
    }
  }

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;

    bool is_from_left = ((i % 2) == 0);
    Solve(h, is_from_left);
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << arr[i][j];
    }
    cout << "\n";
  }

  return 0;
}