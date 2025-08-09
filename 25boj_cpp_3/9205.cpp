// 맥주 마시면서 걸어가기
// https://www.acmicpc.net/problem/9205

#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n += 2; 
    vector<pair<int, int>> pts(n); // 0 = home, n - 1 = festival
    for (int i = 0; i < n; ++i) cin >> pts[i].first >> pts[i].second;

    vector<vector<pair<int, int>>> adj_list(n); // id, dist
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int dist = abs(pts[i].first - pts[j].first) + abs(pts[i].second - pts[j].second);
        adj_list[i].emplace_back(j, dist);
        adj_list[j].emplace_back(i, dist);
      }
    }

    vector<bool> vis(n, false);

    queue<int> que;
    que.push(0);
    vis[0] = true;

    bool ok = false;
    while (que.size()) {
      int u = que.front();
      que.pop();

      if (u == n - 1) {
        ok = true;
        break;
      }

      for (auto e : adj_list[u]) {
        int v, d;
        tie(v, d) = e;
        if (vis[v]) continue;
        if (d > 1000) continue;
        vis[v] = true;
        que.push(v);
      }
    }

    if (ok) cout << "happy\n";
    else cout << "sad\n";
  }

  return 0;
}