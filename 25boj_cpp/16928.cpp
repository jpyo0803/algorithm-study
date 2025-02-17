// 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  vector<int> ls(105);
  for (int i = 0; i < 100; ++i) ls[i] = i;

  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    ls[u] = v;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    ls[u] = v;
  }

  vector<bool> visited(105, false);
  
  queue<pair<int, int>> que; // curr pos, cost
  que.emplace(0, 0);
  visited[0] = true;

  int ans;
  while (que.empty() == false) {
    auto x = que.front();
    que.pop();
    int curr_pos = x.first;
    int cost = x.second;

    if (curr_pos == 99) {
      ans = cost;
      break;
    }

    for (int i = 1; i <= 6; ++i) {
      int next_pos = curr_pos + i;
      if (next_pos >= 100) continue;
      if (visited[next_pos]) continue;
      que.emplace(ls[next_pos], cost + 1);
      visited[ls[next_pos]] = true;
    }
  }

  cout << ans << "\n";

  return 0;
}