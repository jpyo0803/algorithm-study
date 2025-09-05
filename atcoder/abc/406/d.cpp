// D - Garbage Removal (ABC)
// https://atcoder.jp/contests/abc406/tasks/abc406_d

#include <bits/stdc++.h>

using namespace std;

int h, w, n, q, cmd, x, y;
vector<int> r[200005];
vector<int> c[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> h >> w >> n;

  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    r[x].push_back(i);
    c[y].push_back(i);
  }

  vector<bool> used(n + 5, false);
  vector<bool> ur(h + 5, false);
  vector<bool> uc(w + 5, false);

  cin >> q;
  while (q--) {
    cin >> cmd;
    if (cmd == 1) {
      cin >> x;
      if (ur[x]) cout << "0\n";
      else {
        int ans = 0;
        for (auto e : r[x]) {
          if (!used[e]) {
            used[e] = true;
            ans++;
          }
        }
        cout << ans << "\n";
        ur[x] = true;
      }
    } else {
      cin >> y;
      if (uc[y]) cout << "0\n";
      else {
        int ans = 0;
        for (auto e : c[y]) {
          if (!used[e]) {
            used[e] = true;
            ans++;
          }
        }
        cout << ans << "\n";
        uc[y] = true;
      }
    }
  }

  return 0;
}