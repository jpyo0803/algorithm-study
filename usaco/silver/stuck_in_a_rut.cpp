// Stuck in a rut (Silver)
// https://www.acmicpc.net/problem/20649

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<tuple<char, int, int>> vv;
  vector<int> ev, nv;
  for (int i = 0; i < n; ++i) {
    char dir;
    int x, y;
    cin >> dir >> x >> y;
    vv.emplace_back(dir, x, y);
    if (dir == 'E') ev.emplace_back(i);
    else nv.emplace_back(i);
  }

  vector<tuple<int, int, int, int>> cv; // collision
  for (auto i : ev) {
    for (auto j : nv) {
      char dir;
      int ex, ey, nx, ny;
      tie(dir, ex, ey) = vv[i];
      tie(dir, nx, ny) = vv[j];

      if (ex > nx || ny > ey) continue; // they dont cross
      int dx = nx - ex;
      int dy = ey - ny;

      cv.emplace_back(dx, dy, i, j);
    }
  }

  sort(cv.begin(), cv.end(), [](tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
    int da = max(get<0>(a), get<1>(a));
    int db = max(get<0>(b), get<1>(b));
    return da < db;
  });

  vector<int> bv(n, -1); // -1 means not blocked
  vector<pair<int, int>> final_pos(n, {-1, -1});

  for (auto e : cv) {
    int dx, dy, i, j;
    tie(dx, dy, i, j) = e;
    if (dx == dy) continue;

    int ex = get<1>(vv[i]), ey = get<2>(vv[i]);
    int nx = get<1>(vv[j]), ny = get<2>(vv[j]);
    int cx = nx, cy = ey;

    // cout << i << " vs " << j << endl;
    // cout << "final pos of i: " << final_pos[i].first << ", " << final_pos[i].second << endl;
    // cout << "final pos of j: " << final_pos[j].first << ", " << final_pos[j].second << endl;

    if (final_pos[i].first != -1 && final_pos[i].first < cx) continue;
    if (final_pos[j].second != -1 && final_pos[j].second < cy) continue;
    
    if (dx < dy) { // north blocked by east
      bv[j] = i;
      final_pos[j] = {cx, cy};
    } else {
      bv[i] = j;
      final_pos[i] = {cx, cy};
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << i << " by " << bv[i] << endl;
  // }

  vector<int> ans(n, 0);
  for (int i = 0; i < n; ++i) {
    int curr = i;
    while (bv[curr] != -1) {
      curr = bv[curr];
      ans[curr]++;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << "\n";
  }

  return 0;
}