// 2-SAT - 3
// https://www.acmicpc.net/problem/11280

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj_list[20005];
vector<int> adj_list_rev[20005];
stack<int> stk;
bool visited[20005];
vector<int> comps[20005];
int num_comps = 0;
int belong_to[20005];

void Connect(int x, int y) {
  if (x < 0)
    x = -x;
  else
    x += n;
  if (y < 0) y = -y + n;
  adj_list[x].push_back(y);
  adj_list_rev[y].push_back(x);
}

int GetCounterPart(int x) {
  if (x > n) return x - n;
  return x + n;
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
  comps[num_comps].push_back(x);
  belong_to[x] = num_comps;
  for (auto y : adj_list_rev[x]) {
    if (visited[y]) continue;
    Dfs2(y);
  }
}

void SCC() {
  for (int i = 1; i <= 2 * n; ++i) visited[i] = false;

  while (stk.size()) {
    int x = stk.top();
    stk.pop();

    if (visited[x]) continue;
    num_comps++;
    Dfs2(x);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    Connect(x, y);
    Connect(y, x);
  }

  for (int i = 1; i <= 2 * n; ++i) {
    if (visited[i]) continue;
    Dfs1(i);
  }

  SCC();

  bool ok = true;
  for (int i = 1; i <= num_comps; ++i) {
    for (auto x : comps[i]) {
      if (i == belong_to[GetCounterPart(x)]) {
        ok = false;
      }
    }
  }
  cout << (ok ? 1 : 0) << "\n";

  return 0;
}