// 작업
// https://www.acmicpc.net/problem/2056

#include <bits/stdc++.h>

using namespace std;

int n;
int dist[10005];  // start time
int cost[10005];
int indeg[10005];
vector<int> adj_list[10005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    dist[i] = -1;
    cin >> cost[i];

    int x;
    cin >> x;
    while (x--) {
      int f;
      cin >> f;
      adj_list[f].push_back(i);
      indeg[i]++;
    }
  }

  queue<int> que;
  for (int i = 1; i <= n; ++i) {
    if (indeg[i] == 0) {
      que.push(i);
      dist[i] = 0;
    }
  }

  while (que.size()) {
    int u = que.front();
    que.pop();

    for (auto v : adj_list[u]) {
      dist[v] = max(dist[v], dist[u] + cost[u]);
      indeg[v]--;
      if (indeg[v] == 0) que.push(v);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, dist[i] + cost[i]);
  }
  cout << ans << "\n";

  return 0;
}