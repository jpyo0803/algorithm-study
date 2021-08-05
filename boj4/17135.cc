//
// Castle Defense
// Link: https://www.acmicpc.net/problem/17135
//

#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

constexpr int kMax = 15;
constexpr int INF = 987654321;

int N, M, D, e, ans;

vector<pair<int, int>> enemies;
vector<int> archers;

bool map[kMax][kMax];

bool cmpr(pair<int, int>& p1, pair<int, int>& p2) {
  return p1.first < p2.first;
}

int GetDistance(int r1, int c1, int r2, int c2) {
  return abs(r1 - r2) + abs(c1 - c2);
}

int Max(int x, int y) { return x < y ? y : x; }
bool InRange(int r, int c) { return r >= 0 && r < N && c >= 0 && c < M; }

int Simulate(vector<int>& archers) {
  int kill_count = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      map[i][j] = false;
    }
  }

  for (auto& enemy : enemies) map[enemy.first][enemy.second] = true;

  int ar = N;
  while (ar > 0) {
    pair<pair<int, int>, int> targets[3];
    for (int i = 0; i < 3; i++) {
      targets[i].second = INF;
      targets[i].first.second = INF;
      int ac = archers[i];
      for (int er = ar - D; er < ar; er++) {
        int wl = D - ar + er;
        for (int ec = ac - wl; ec <= ac + wl; ec++) {
          if (!InRange(er, ec)) continue;
          if (!map[er][ec]) continue;

          int dist = GetDistance(ar, ac, er, ec);
          if (dist > D) continue;
          if (dist > targets[i].second) continue;
          if (dist == targets[i].second && ec >= targets[i].first.second) continue;
          targets[i].second = dist;
          targets[i].first.first = er;
          targets[i].first.second = ec;
        }
      }
    }
    for (int i = 0; i < 3; i++) {
      int tr = targets[i].first.first;
      int tc = targets[i].first.second;
      if (!InRange(tr, tc)) continue;

      if (!map[tr][tc]) continue;
      map[tr][tc] = false;
      kill_count++;
    }
    ar--;
  }
  return kill_count;
}

void DFS(vector<int>& archers) {
  if (archers.size() == 3) {
    ans = Max(ans, Simulate(archers));
    return;
  }

  int begin = archers.size() ? archers.back() + 1 : 0;
  for (int i = begin; i < M; i++) {
    archers.push_back(i);
    DFS(archers);
    archers.pop_back();
  }
}

int main() {
  scanf("%d%d%d", &N, &M, &D);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &e);
      if (e) enemies.emplace_back(i, j);
    }
  }

  ans = 0;
  DFS(archers);
  printf("%d\n", ans);
  return 0;
}