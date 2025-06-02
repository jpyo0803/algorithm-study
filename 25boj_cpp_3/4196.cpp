// 도미노
// https://www.acmicpc.net/problem/4196

#include <bits/stdc++.h>

using namespace std;

int t, n, m;

vector<int> adj_list[100005];
vector<int> adj_list_rev[100005];

bool visited[100005];

stack<int> stk;
int num_components;
vector<int> components[100005];
int belong_to[100005];
set<int> adj_list_scc[100005];

int in_deg[100005];

void ResetVisited() {
  for (int i = 1; i <= n; ++i) visited[i] = false;
}

void ResetAdjList() {
  for (int i = 1; i <= n; ++i) {
    adj_list[i].clear();
    adj_list_rev[i].clear();
  }
}

void ResetSCC() {
  for (int i = 1; i <= num_components; ++i) {
    components[i].clear();
    adj_list_scc[i].clear();
  }
  num_components = 0;
}

void ResetBelongTo() {
  for (int i = 1; i <= n; ++i) belong_to[i] = 0;
}

void ResetIndeg() {
  for (int i = 1; i <= num_components; ++i) in_deg[i] = 0;
}

void Dfs1(int x) {
  visited[x] = true;
  for (auto y : adj_list[x]) {
    if (visited[y]) continue;
    Dfs1(y);
  }
  stk.push(x);
}

void Dfs2(int x) {
  visited[x] = true;
  components[num_components].push_back(x);
  belong_to[x] = num_components;
  for (auto y : adj_list_rev[x]) {
    if (visited[y]) continue;
    Dfs2(y);
  }
}

void SCC() {
  ResetSCC();
  ResetVisited();
  ResetBelongTo();

  while (stk.empty() == false) {
    int x = stk.top();
    stk.pop();

    if (visited[x] == false) {
      num_components++; // 1-based
      Dfs2(x);
    }
  }
}

void Dfs3(int x) {
  visited[x] = true;
  for (auto y : adj_list_scc[x]) {
    if (visited[y]) continue;
    Dfs3(y);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n >> m;

    ResetSCC();
    ResetAdjList();

    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      adj_list[x].push_back(y);
      adj_list_rev[y].push_back(x);
    }

    ResetVisited();
    for (int i = 1; i <= n; ++i) {
      if (visited[i] == false) {
        Dfs1(i);
      }
    }
    // by now stack is ready

    SCC();

    ResetIndeg();
    for (int u = 1; u <= num_components; ++u) {
      for (auto x : components[u]) { // x = component member, O(n)
        for (auto e : adj_list[x]) { // O(n + m)
          int v = belong_to[e];
          if (u == v) continue;
          adj_list_scc[u].insert(v);
          in_deg[v]++;
        }
      }
    }

    int ans = 0;

    for (int i = 1; i <= num_components; ++i) {
      if (in_deg[i] == 0) ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}