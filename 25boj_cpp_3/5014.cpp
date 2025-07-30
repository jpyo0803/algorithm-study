// 스타트링크
// https://www.acmicpc.net/problem/5014

#include <bits/stdc++.h>

using namespace std;

int f, s, g, u, d;

int dist[1000005];

bool OutOfRange(int x) { return x < 1 || x > f; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> f >> s >> g >> u >> d;
  for (int i = 1; i <= f; ++i) dist[i] = -1;

  queue<int> que;
  que.push(s);
  dist[s] = 0;

  int ans = -1;
  while (que.size()) {
    auto curr = que.front();
    que.pop();

    if (curr == g) {
      ans = dist[curr];
      break;
    }

    if (curr + u <= f && dist[curr + u] == -1) {
      dist[curr + u] = dist[curr] + 1;
      que.push(curr + u);
    }
    if (curr - d >= 1 && dist[curr - d] == -1) {
      dist[curr - d] = dist[curr] + 1;
      que.push(curr - d);
    }
  }

  if (ans == -1)
    cout << "use the stairs\n";
  else
    cout << ans << "\n";

  return 0;
}