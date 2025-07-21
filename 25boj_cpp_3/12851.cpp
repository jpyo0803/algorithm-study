// 숨바꼭질 2
// https://www.acmicpc.net/problem/12851

#include <bits/stdc++.h>

using namespace std;

int n, k;

int dist[200010];
int cnt[200010][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < 200010; ++i) dist[i] = -1;

  queue<int> que;
  que.push(n);
  dist[n] = 0;
  cnt[n][0] = 1;

  int ans1, ans2;
  while (que.size()) {
    int u = que.front();
    que.pop();

    int d = dist[u];
    if (u == k) {
      ans1 = d;
      ans2 = cnt[u][d % 2];
      break;
    }

    if (u - 1 >= 0) {
      if (dist[u - 1] == -1) {
        dist[u - 1] = d + 1;
        que.push(u - 1);
      }
      cnt[u - 1][(d + 1) % 2] += cnt[u][d % 2];
    } 
    if (u + 1 <= 200000) {
      if (dist[u + 1] == -1) {
        dist[u + 1] = d + 1;
        que.push(u + 1);
      }
      cnt[u + 1][(d + 1) % 2] += cnt[u][d % 2];
    }
    if (u * 2 <= 200000) {
      if (dist[u * 2] == -1) {
        dist[u * 2] = d + 1;
        que.push(u * 2);
      } 
      cnt[u * 2][(d + 1) % 2] += cnt[u][d % 2];
    }
  }

  cout << ans1 << "\n" << ans2 << "\n";

  return 0;
}