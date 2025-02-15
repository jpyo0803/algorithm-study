// 숨바꼭질 3
// https://www.acmicpc.net/problem/13549

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  deque<pair<int, int>> dq; // curr_pos, cost

  vector<bool> visited(200010, false);

  dq.emplace_back(n, 0);

  int ans;
  while (dq.empty() == false) {
    auto p = dq.front();
    dq.pop_front();

    int u = p.first;
    int cost = p.second;

    if (u == k) {
      ans = cost;
      break;
    }

    if (visited[u] == true) continue;
    visited[u] = true;

    int v = u * 2;
    if (v < 200010 && visited[v] == false) {
      dq.emplace_front(v, cost);
    }
    v = u + 1;
    if (v < 200010 && visited[v] == false) {
      dq.emplace_back(v, cost + 1);
    }
    v = u - 1;
    if (v >= 0 && visited[v] == false) {
      dq.emplace_back(v, cost + 1);
    }
  }

  cout << ans << "\n";

  return 0;
}