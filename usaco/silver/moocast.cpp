// Moocast (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=668

#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool WithinRange(int x1, int x2, int y1, int y2, int p) {
  int dx = x1 - x2;
  int dy = y1 - y2;
  return dx * dx + dy * dy <= p * p;
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);
  
  ifstream cin("moocast.in");
  ofstream cout("moocast.out");

  int n;
  cin >> n;
  vector<tuple<int, int, int>> cv(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<0>(cv[i]);
    cin >> get<1>(cv[i]);
    cin >> get<2>(cv[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    queue<int> q;
    q.push(i);
    vector<bool> vis(n, false);
    vis[i] = true;

    int cnt = 0;
    while (q.size()) {
      cnt++;
      auto now = q.front();
      q.pop();
      int x1 = get<0>(cv[now]);
      int y1 = get<1>(cv[now]);
      int p = get<2>(cv[now]);
      for (int j = 0; j < n; ++j) {
        if (vis[j]) continue;
        int x2 = get<0>(cv[j]);
        int y2 = get<1>(cv[j]);
        if (WithinRange(x1, x2, y1, y2, p) == false) continue;
        vis[j] = true;
        q.push(j);
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << "\n";

  return 0;
}