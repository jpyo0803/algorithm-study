// Stuck in A Rut
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1061

#include <bits/stdc++.h>

using namespace std;

struct Cow {
  char dir;
  int x, y;
  int moves;

  Cow(char _dir, int _x, int _y) : dir(_dir), x(_x), y(_y), moves(-1) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<Cow> cows;
  for (int i = 0; i < N; ++i) {
    char dir;
    int x, y;
    cin >> dir >> x >> y;
    cows.emplace_back(dir, x, y);
  }

  int t = 0;  // current time
  while (true) {
    int min_bt = -1;
    vector<int> ebt(N, -1);

    for (int i = 0; i < N; ++i) {
      if (cows[i].moves != -1) continue;  // already blocked

      for (int j = 0; j < N; ++j) {
        if (cows[i].dir == cows[j].dir)
          continue;  // same dir cannot block each other

        Cow nc = cows[i];
        Cow ec = cows[j];
        if (nc.dir == 'E') {
          swap(nc.x, nc.y);
          swap(ec.x, ec.y);
        }

        if (ec.y <= nc.y) continue;

        if (ec.moves == -1) {  // still moving
          if (nc.x < ec.x - t)
            continue;  // from the beginning, it already passed nc.x
          if (ec.x + ec.y <= nc.x + nc.y) continue;
        } else {                      // already stopped
          if (ec.x < nc.x) continue;  // stopped even before blocking nc
          if (nc.x < ec.x - ec.moves) continue;
        }
        int bt = t + ec.y - nc.y;
        if (ebt[i] == -1 || bt < ebt[i]) {
          ebt[i] = bt;
        }
      }

      if (ebt[i] != -1) {
        if (min_bt == -1 || ebt[i] < min_bt) {
          min_bt = ebt[i];
        }
      }
    }

    if (min_bt == -1) break;  // no more blocking

    for (int i = 0; i < N; ++i) {
      if (cows[i].moves != -1) continue;

      if (cows[i].dir == 'N') {
        cows[i].y += min_bt - t;
      } else {
        cows[i].x += min_bt - t;
      }

      if (ebt[i] == min_bt) {
        cows[i].moves = min_bt;
      }
    }

    t = min_bt;
  }

  for (int i = 0; i < N; ++i) {
    if (cows[i].moves == -1) {
      cout << "Infinity\n";
    } else {
      cout << cows[i].moves << "\n";
    }
  }

  return 0;
}