// Stuck in a Rut (Bronze)
// https://www.acmicpc.net/problem/20652


/*
  As x's and y's coodinates are all different, N-N or E-E pairs cannot collide

  Only N-E pair can collide if e.x < n.x && e.y > n.y
*/
#include <bits/stdc++.h>

using namespace std;

int n;


bool IsCrossing(int nx, int ny1, int ny2, int ey, int ex1, int ex2) {
  if (nx < ex1 || ex2 < nx) return false;
  if (ey < ny1 || ny2 < ey) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<tuple<int, int, int, int>> nv, ev; // x, y1, y2, id
  for (int i = 0; i < n; ++i) {
    char dir;
    int x, y;
    cin >> dir >> x >> y;
    if (dir == 'N') {
      nv.emplace_back(x, y, 2e9, i);
    } else {
      ev.emplace_back(y, x, 2e9, i);
    }
  }

  vector<int> ans(n, -1);

  int n_len = nv.size();
  int e_len = ev.size();

  while (true) {
    int min_d = 2e9;
    int tid, tid2;
    int stop_pos;
    bool n_stop;

    for (int i = 0; i < n_len; ++i) {
      int nx, ny1, ny2, nid;
      tie(nx, ny1, ny2, nid) = nv[i];

      for (int j = 0; j < e_len; ++j) {
        int ey, ex1, ex2, eid;
        tie(ey, ex1, ex2, eid) = ev[j];

        if (!IsCrossing(nx, ny1, ny2, ey, ex1, ex2)) continue;

        int dx = nx - ex1;
        int dy = ey - ny1;
        if (dx == dy) continue;

        if (dx < dy) {
          // N will be blocked
          if (dy < min_d) {
            min_d = dy;
            tid = nid;
            tid2 = i;
            stop_pos = ey - 1;
            n_stop = true;
          }
        } else {
          // E will be blocked
          if (dx < min_d) {
            min_d = dx;
            tid = eid;
            tid2 = j;
            stop_pos = nx - 1;
            n_stop = false;
          }
        }
      }
    }

    if (min_d == 2e9) break; // no more collsion

    ans[tid] = min_d;
    if (n_stop)  {
      get<2>(nv[tid2]) = stop_pos;
    } else {
      get<2>(ev[tid2]) = stop_pos;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (ans[i] == -1) cout << "Infinity\n";
    else cout << ans[i] << "\n";
  }

  return 0;
}