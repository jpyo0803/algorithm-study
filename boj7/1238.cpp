// 파티
// https://www.acmicpc.net/problem/1238

#include <stdio.h>

#include <queue>
#include <utility>
#include <vector>

using namespace std;

int N, M, X, U, V, T;
int dist[1001][2];
vector<pair<int, int>> adj[1001][2];  // v, w;

int Solve(int S) {
  for (int i = 1; i <= N; i++) dist[i][0] = dist[i][1] = 987654321;

  for (int i = 0; i < 2; i++) {
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, S);
    dist[S][i] = 0;

    while (!pq.empty()) {
      int cost = -pq.top().first;
      int now = pq.top().second;
      pq.pop();

      if (cost > dist[now][i]) continue;

      for (auto& next : adj[now][i]) {
        int next_cost = cost + next.second;
        if (next_cost < dist[next.first][i]) {
          dist[next.first][i] = next_cost;
          pq.emplace(-next_cost, next.first);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int sum = dist[i][0] + dist[i][1];
    ans = ans < sum ? sum : ans;
  }

  return ans;
}

int main() {
  scanf("%d%d%d", &N, &M, &X);
  for (int m = 0; m < M; m++) {
    scanf("%d%d%d", &U, &V, &T);
    adj[U][0].emplace_back(V, T);
    adj[V][1].emplace_back(U, T);
  }
  printf("%d\n", Solve(X));
  return 0;
}
