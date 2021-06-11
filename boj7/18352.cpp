// 특정 거리의 도시 찾기
// https://www.acmicpc.net/problem/18352

#include <stdio.h>

#include <queue>
#include <vector>

using namespace std;

int N, M, K, X, A, B;
vector<int> adj[300001];
int dist[300001];

void Solve(int K, int X) {
  for (int i = 1; i <= N; i++) dist[i] = 987654321;

  priority_queue<pair<int, int>> pq;
  pq.emplace(0, X);
  dist[X] = 0;

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int now = pq.top().second;
    pq.pop();
    if (cost > dist[now]) continue;

    for (auto next : adj[now]) {
      int next_cost = cost + 1;
      if (next_cost < dist[next]) {
        dist[next] = next_cost;
        pq.emplace(-next_cost, next);
      }
    }
  }

  bool ans_exist = false;
  for (int i = 1; i <= N; i++) {
    if (dist[i] == K) {
      printf("%d\n", i);
      if (!ans_exist) ans_exist = true;
    }
  }

  if (!ans_exist) printf("-1\n");
}

int main() {
  scanf("%d%d%d%d", &N, &M, &K, &X);
  for (int m = 0; m < M; m++) {
    scanf("%d%d", &A, &B);
    adj[A].push_back(B);
  }

  Solve(K, X);
  return 0;
}
