// 숨바꼭질
// https://www.acmicpc.net/problem/1697

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  vector<bool> visited(200010, false);
  queue<pair<int, int>> que; // curr pos, dst

  que.emplace(n, 0);

  int ans;
  while (que.empty() == false) {
    auto e = que.front();
    que.pop();

    int u = e.first;
    int dst = e.second;
    if (visited[u] == true) continue;
    visited[u] = true;

    if (u == k) {
      ans = dst;
      break;
    }

    if (u - 1 >= 0 && visited[u - 1] == false) que.emplace(u - 1, dst + 1);
    if (u + 1 < 200010 && visited[u + 1] == false) que.emplace(u + 1, dst + 1);
    if (u * 2 < 200010 && visited[u * 2] == false) que.emplace(u * 2, dst + 1);
  }

  cout << ans << "\n";

  return 0;
}