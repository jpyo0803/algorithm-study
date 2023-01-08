// 도로 포장
// https://www.acmicpc.net/problem/1162

#include <stdint.h>
#include <stdio.h>

#include <queue>
#include <utility>
#include <vector>

constexpr int64_t kInf = 987'654'321'987'654;

using namespace std;

struct Info {
  int v, k;
  int64_t cost;
  Info(int _v, int _k, int64_t _cost) : v(_v), k(_k), cost(_cost) {}
};

struct Comparator {
  bool operator()(const Info& lhs, const Info& rhs) {
    return lhs.cost < rhs.cost;
  }
};

int N, M, K;

vector<pair<int, int>> adj[10'010];
int64_t cache[10'010][21];

int64_t Solve() {
  for (int n = 0; n <= N; ++n) {
    for (int k = 0; k <= K; ++k) {
      cache[n][k] = kInf;
    }
  }

  priority_queue<Info, vector<Info>, Comparator> pq;
  pq.emplace(1, 0, 0);

  int64_t ans = kInf;
  while (!pq.empty()) {
    int64_t cost = -pq.top().cost;
    int v = pq.top().v;
    int k = pq.top().k;
    pq.pop();

    if (v == N) {
      ans = cost < ans ? cost : ans;
    }
    if (cache[v][k] < cost) continue;

    for (auto& p : adj[v]) {
      if (cost + p.second < cache[p.first][k]) {
        pq.emplace(p.first, k, -(cost + p.second));
        cache[p.first][k] = cost + p.second;
      }
      if (k + 1 <= K && cost < cache[p.first][k + 1]) {
        pq.emplace(p.first, k + 1, -cost);
        cache[p.first][k + 1] = cost;
      }
    }
  }
  return ans;
}

int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int m = 0; m < M; ++m) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  printf("%lld\n", Solve());

  return 0;
}