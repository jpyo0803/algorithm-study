// Modern Art (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=737

#include <bits/stdc++.h>

using namespace std;

struct Rect {
  int bl_x, bl_y, tr_x, tr_y;

  Rect() : bl_x(1e9), bl_y(1e9), tr_x(-1), tr_y(-1) {}
};

bool rect_valid[10];

bool IsTrespass(int x, int y, const Rect& a) {  //
  if (x >= a.bl_x && x <= a.tr_x && y >= a.bl_y && y <= a.tr_y) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<Rect> dim(10);

  vector<vector<int>> canvas(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    string line;
    cin >> line;
    for (int j = 0; j < N; ++j) {
      canvas[i][j] = line[j] - '0';

      auto& rect = dim[canvas[i][j]];
      rect.bl_x = min(rect.bl_x, j);
      rect.bl_y = min(rect.bl_y, i);
      rect.tr_x = max(rect.tr_x, j);
      rect.tr_y = max(rect.tr_y, i);

      rect_valid[canvas[i][j]] = true;
    }
  }

  int ans = 0;
  for (int k = 1; k <= 9; ++k) {
    if (!rect_valid[k]) continue;
    const auto& rect = dim[k];

    bool ok = true;
    for (int i = rect.bl_y; i <= rect.tr_y; ++i) {
      for (int j = rect.bl_x; j <= rect.tr_x; ++j) {
        if (canvas[i][j] != k) continue;

        bool trespass = false;
        for (int k2 = 1; k2 <= 9; ++k2) {
          if (k == k2) continue;
          if (!rect_valid[k2]) continue;

          trespass |= IsTrespass(j, i, dim[k2]);

          if (trespass) break;
        }
        if (trespass) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }

    if (ok) {
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}