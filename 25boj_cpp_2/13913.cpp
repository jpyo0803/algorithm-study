// 숨바꼭질 4
// https://www.acmicpc.net/problem/13913

#include <bits/stdc++.h>

using namespace std;

int n, k;
int p[200010];
int dist[200010];

void PrintPath(int x) {
  if (x != p[x]) {
    PrintPath(p[x]);
  }
  cout << x << " ";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 200010; ++i) {
    p[i] = dist[i] = -1;
  }

  cin >> n >> k;

  queue<pair<int, int>> que;  // curr, cost, prev
  dist[n] = 0;
  p[n] = n;
  que.emplace(n, n);

  while (que.empty() == false) {
    int u = que.front().first;
    int parent = que.front().second;
    que.pop();

    if (u + 1 < 200010 && dist[u + 1] == -1) {
      dist[u + 1] = dist[u] + 1;
      p[u + 1] = u;
      que.emplace(u + 1, u);
    }
    if (u - 1 >= 0 && dist[u - 1] == -1) {
      dist[u - 1] = dist[u] + 1;
      p[u - 1] = u;
      que.emplace(u - 1, u);
    }
    if (u * 2 < 200010 && dist[u * 2] == -1) {
      dist[u * 2] = dist[u] + 1;
      p[u * 2] = u;
      que.emplace(u * 2, u);
    }
  }

  cout << dist[k] << "\n";
  PrintPath(k);
  cout << "\n";

  return 0;
}