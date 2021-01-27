//
// Strongly Connected Component
// Link: https://www.acmicpc.net/problem/2150
//

#include <cstdio>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int Min(int x, int y) { return x < y ? x : y; }

vector<set<int>> adj;
vector<int> discovered, ssc_id;
vector<set<int>> answer;
stack<int> stk;

int V, E, counter, ssc_counter;

int TarjanSCC(int u) {
  int ret = discovered[u] = counter++;
  stk.push(u);
  for (auto v : adj[u]) {
    if (discovered[v] == -1) {
      ret = Min(ret, TarjanSCC(v));
    } else if (ssc_id[v] == -1) {
      ret = Min(ret, discovered[v]);
    }
  }

  if (ret == discovered[u]) {
    int min_v = u;
    set<int> panswer;
    while (true) {
      int t = stk.top();
      stk.pop();
      panswer.insert(t);
      min_v = Min(min_v, t);
      ssc_id[t] = ssc_counter;
      if (t == u) break;
    }
    answer[min_v] = panswer;
    ssc_counter++;
  }
  return ret;
}

int main() {
  scanf("%d%d", &V, &E);
  adj = answer = vector<set<int>>(V + 1);
  discovered = ssc_id = vector<int>(V + 1, -1);
  counter = ssc_counter = 1;

  for (int e = 0; e < E; e++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].insert(v);
  }

  for (int u = 1; u <= V; u++) {
    if (discovered[u] == -1) TarjanSCC(u);
  }

  printf("%d\n", ssc_counter - 1);
  for (auto& m : answer) {
    if (m.empty()) continue;
    for (auto y : m) {
      printf("%d ", y);
    }
    printf("-1\n");
  }

  return 0;
}
