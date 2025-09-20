// 점프 점프 
// https://www.acmicpc.net/problem/11060

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
int arr[1005];
int dist[1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 0; i < n; ++i) dist[i] = -1;

  queue<int> que;
  que.push(0);
  dist[0] = 0;

  int ans = -1;
  while (que.size()) {
    int u = que.front();
    que.pop();

    if (u == n - 1) {
      ans = dist[u];
      break;
    }

    for (int i = 1; i <= arr[u]; ++i) {
      int v = u + i;
      if (v >= n) continue;
      if (dist[v] != -1) continue;
      dist[v] = dist[u] + 1;
      que.push(v);
    }
  }

  cout << ans << "\n";

  return 0;
}