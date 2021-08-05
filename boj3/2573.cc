//
// Iceberg
// Problem: https://www.acmicpc.net/problem/2573
//

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

constexpr int MAX{300};

int N, M;
int remain_map[MAX][MAX];
int subtract_map[MAX][MAX];
bool visited[MAX][MAX];

vector<pair<int, int>> remain_locations;
vector<pair<int, int>> subtract_locations;

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool IsDivided(pair<int, int> &start) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visited[i][j] = false;
    }
  }

  vector<pair<int, int>> frontier, next;
  frontier.push_back(start);
  int num_visited = 1;
  visited[start.first][start.second] = true;
  while (!frontier.empty()) {
    next.clear();
    for (auto &u : frontier) {
      for (int i = 0; i < 4; i++) {
        int vr = u.first + d[i][0];
        int vc = u.second + d[i][1];
        if (vr >= 0 && vr < N && vc >= 0 && vc < M && !visited[vr][vc] && remain_map[vr][vc] > 0) {
          visited[vr][vc] = true;
          num_visited += 1;
          next.emplace_back(vr, vc);
        }
      }
    }

    swap(frontier, next);
  }
  return num_visited != remain_locations.size();
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &remain_map[i][j]);
      if (remain_map[i][j] > 0) {
        remain_locations.emplace_back(i, j);
      }
    }
  }

  int year = 0;

  while (!remain_locations.empty()) {
    if (IsDivided(remain_locations[0])) {
      printf("%d\n", year);
      return 0;
    }
    subtract_locations.clear();
    for (auto& u : remain_locations) {
      int subtract_count = 0;
      for (int i = 0; i < 4; i++) {
        int vr = u.first + d[i][0];
        int vc = u.second + d[i][1];
        if (vr >= 0 && vr < N && vc >= 0 && vc < M && remain_map[vr][vc] == 0) {
          subtract_count += 1;
        }
      }
      subtract_map[u.first][u.second] = subtract_count;
      if (subtract_count > 0) {
        subtract_locations.push_back(u);
      }
    }
    for (auto& u : subtract_locations) {
      remain_map[u.first][u.second] -= subtract_map[u.first][u.second];
      if (remain_map[u.first][u.second] < 0) {
        remain_map[u.first][u.second] = 0;
      }
    }
    remain_locations.clear();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (remain_map[i][j] > 0) {
          remain_locations.emplace_back(i, j);
        }
      }
    }
    year += 1;
  }

  printf("0\n");
  return 0;
}
