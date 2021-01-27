//
// 도미노
// Link: https://www.acmicpc.net/problem/4196
//

#include <cstdio>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int T, M, N;
vector<vector<int>> adj;
vector<int> discovered, scc_id, indegree;
stack<int> stk;
int discover_count, scc_count;

int Min(int x, int y) { return x < y ? x : y; }

int TarjanSCC(int u, int root) {
  int ret = discovered[u] = discover_count++;
  stk.push(u);

  for (auto& v : adj[u]) {
    if (discovered[v] == -1) {
      ret = Min(ret, TarjanSCC(v, root));
    } else if (scc_id[v] == -1) {
      ret = Min(ret, discovered[v]);
    } else {
      indegree[scc_id[v]]++;
    }
  }

  if (ret == discovered[u]) {
    while (true) {
      int t = stk.top();
      stk.pop();
      scc_id[t] = scc_count;
      if (t == u) {
        if (u != root) indegree[scc_id[u]]++;
        break;
      }
    }
    scc_count++;
  }
  return ret;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d%d", &N, &M);
    discover_count = scc_count = 0;
    adj = vector<vector<int>>(N + 1);
    discovered = scc_id = vector<int>(N + 1, -1);
    indegree = vector<int>(N + 1, 0);
    while (!stk.empty()) stk.pop();

    for (int m = 0; m < M; m++) {
      int x, y;
      scanf("%d%d", &x, &y);
      adj[x].push_back(y);
    }
    for (int u = 1; u <= N; u++) {
      if (discovered[u] == -1) {
        TarjanSCC(u, u);
      }
    }
    int push_count = 0;
    for (int i = 0; i < scc_count; i++) {
      if (indegree[i] == 0) push_count++;
    }

    printf("%d\n", push_count);
  }
  return 0;
}
