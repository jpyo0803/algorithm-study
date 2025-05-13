// 최소비용 구하기
// https://www.acmicpc.net/problem/1916

#include <bits/stdc++.h>

using namespace std;

int dp[1010];
vector<pair<int, int>> adj_list[1010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, s, t;
  cin >> N >> M;

  for (int i = 1; i <= N; ++i) {
    dp[i] = 1e9;
  }

  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj_list[a].emplace_back(b, c);
  }

  cin >> s >> t;

  priority_queue<pair<int, int>> pq;
  pq.emplace(0, s);

  while (pq.empty() == false) {
    int u = pq.top().second;
    int dist = -pq.top().first;
    pq.pop();

    if (dp[u] <= dist) {
      continue;
    }
    dp[u] = dist;

    if (u == t) break;

    for (auto [v, w] : adj_list[u]) {
      if (dist + w < dp[v]) {
        pq.emplace(-(dist + w), v);
      }
    }
  }

  cout << dp[t] << "\n";

  return 0;
}