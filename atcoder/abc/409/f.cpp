// F - Connecting Points (ABC)
// https://atcoder.jp/contests/abc409/tasks/abc409_f

#include <bits/stdc++.h>

using namespace std;

int n, q;

int Dist(pair<int, int> p1, pair<int, int> p2) {
  return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int p[3010];
int GetRoot(int x) {
  if (p[x] == x) return x;
  return p[x] = GetRoot(p[x]);
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 1; i <= 3005; ++i) p[i] = i;

  cin >> n >> q;

  vector<pair<int, int>> v(3010);
  for (int i = 1; i <= n; ++i) cin >> v[i].first >> v[i].second;

  priority_queue<tuple<int, int, int>> pq;
  for (int i = 1; i <= n - 1; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int d = Dist(v[i], v[j]);
      pq.emplace(-d, i, j);
    }
  }

  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      n++;
      cin >> v[n].first >> v[n].second;
      for (int i = 1; i <= n - 1; ++i) {
        int d = Dist(v[i], v[n]);
        pq.emplace(-d, i, n);
      }
    } else if (cmd == 2) {
      int mind = -1;
      if (pq.size()) {
        int d, x, y;
        tie(d, x, y) = pq.top();
        
        d = -d;
        while (pq.size()) {
          int d2, x2, y2;
          tie(d2, x2, y2) = pq.top();
          d2 = -d2;
          if (d != d2) break;

          pq.pop();
          int rx = GetRoot(x2), ry = GetRoot(y2);
          if (rx == ry) continue;
          p[ry] = rx;
          mind = d;
        }

        while (pq.size()) {
          int d, x ,y;
          tie(d, x, y) = pq.top();
          if (GetRoot(x) != GetRoot(y)) break;
          pq.pop();
        }
      } 

      cout << mind << "\n";
    } else {
      int u, v;
      cin >> u >> v;
      if (GetRoot(u) == GetRoot(v)) cout << "Yes\n";
      else cout << "No\n";
    }
  }

  return 0;
}