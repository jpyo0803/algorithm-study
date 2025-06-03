// 축구 전술
// https://www.acmicpc.net/problem/3977

#include <bits/stdc++.h>

using namespace std;

int t, n, m;

vector<int> adj_list[100005];
vector<int> adj_list_rev[100005];
set<int> adj_list_scc[100005];

stack<int> stk;
bool visited[100005];
int num_comp = 0;
vector<int> comps[100005];
int in_deg[100005];
int belong_to[100005];

void ResetVisited() { for (int i = 0; i < n; ++i) visited[i] = false; }

void ResetSCC() {
  // call it at the end
  for (int i = 0; i < n; ++i) {
    adj_list[i].clear();
    adj_list_rev[i].clear();
    belong_to[i] = -1;
  }

  for (int i = 0; i < num_comp; ++i) {
    adj_list_scc[i].clear();
    comps[i].clear();
    in_deg[i] = 0;
  }
  num_comp = 0;
}

void Dfs1(int x) {
  visited[x] = true;
  for (auto y : adj_list[x]) {
    if (visited[y] == false) Dfs1(y);
  }
  stk.push(x);
}

void Dfs2(int x) {
  visited[x] = true;
  comps[num_comp].push_back(x);
  belong_to[x] = num_comp;

  for (auto y : adj_list_rev[x]) {
    if (visited[y] == false) Dfs2(y);
  }
}

void SCC() {
  ResetVisited();

  while (stk.size()) {
    int x = stk.top();
    stk.pop();

    if (visited[x]) continue;
    Dfs2(x);
    num_comp++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    ResetSCC();

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      adj_list[a].push_back(b);
      adj_list_rev[b].push_back(a);
    }

    ResetVisited();
    for (int i = 0; i < n; ++i) {
      if (visited[i] == false) Dfs1(i);
    }
  
    SCC();

    for (int i = 0; i < n; ++i) {
      int u = belong_to[i];
      for (int j : adj_list[i]) {
        int v = belong_to[j];
        if (u == v) continue;
        adj_list_scc[u].insert(v);
        in_deg[v]++;
      }
    }

    int in_deg_cnt = 0;
    int targ_comp;
    for (int i = 0; i < num_comp; ++i) {
      if (in_deg[i] == 0) {
        in_deg_cnt++;
        targ_comp = i;
      }
    }

    if (in_deg_cnt == 1) {
      sort(comps[targ_comp].begin(), comps[targ_comp].end());
      for (auto e : comps[targ_comp]) {
        cout << e << "\n";
      }
    } else {
      cout << "Confused\n";
    }
    cout << "\n";
  }

  return 0;
}