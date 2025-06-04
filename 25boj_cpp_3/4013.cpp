// ATM
// https://www.acmicpc.net/problem/4013

#include <bits/stdc++.h>

using namespace std;

int n, m, s, p;
bool visited[500005];
void ResetVisited() { for (int i = 1;  i <= n; ++i) visited[i] = false ;}
int cash[500005];
bool has_restaurant[500005];

vector<int> adj_list[500005];
vector<int> adj_list_rev[500005];
set<int> adj_list_scc[500005];
stack<int> stk;
int belong_to[500005];

vector<int> comps[500005];
int num_comps;
int comp_cash[500005];
int dp[500005];

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
  comps[num_comps].push_back(x);
  comp_cash[num_comps] += cash[x];
  belong_to[x] = num_comps;

  for (auto y : adj_list_rev[x]) {
    if (visited[y]) continue;
    Dfs2(y);
  }
}

void SCC() {
  ResetVisited();

  while (stk.size()) {
    int x = stk.top();
    stk.pop();
    if (visited[x]) continue;
    num_comps++;
    Dfs2(x);
  }
}

int Solve(int x) {
  if (visited[x]) return dp[x];
  
  int ret = -2e9;
  for (auto y : adj_list_scc[x]) {
    ret = max(ret, Solve(y));
  }
  // 만약 ret이 -2e9가 아니라면 적어도 child중에 하나는 valid
  // 만약 ret이 -2e9라면, 현재 노드에 레스토랑이 있는지 확인 없으면 그대로 -2e9 리턴
  if (ret == -2e9) {
    if (has_restaurant[x]) ret = comp_cash[x];
  } else {
    ret += comp_cash[x];
  }

  dp[x] = ret;
  visited[x] = true; // Acyclic이 보장되기에 Solve() 이후에 마킹해도
  
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj_list[x].push_back(y);
    adj_list_rev[y].push_back(x);
  }

  for (int i = 1; i <= n; ++i) cin >> cash[i];

  cin >> s >> p;
  
  for (int i = 1; i <= n; ++i) {
    if (visited[i]) continue;
    Dfs1(i);
  }
  
  SCC();

  for (int i = 0; i < p; ++i) {
    int x;
    cin >> x;
    has_restaurant[belong_to[x]] = true;
  }

  for (int u = 1; u <= num_comps; ++u) {
    for (auto x : comps[u]) {
      for (auto y : adj_list[x]) {
        int v = belong_to[y];
        if (u == v) continue;
        adj_list_scc[u].insert(v);
      }
    }
  }

  ResetVisited();

  cout << max(Solve(belong_to[s]), 0) << "\n";

  return 0;
}