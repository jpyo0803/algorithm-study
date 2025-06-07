// 2-SAT - 4
// https://www.acmicpc.net/problem/11281

#include <bits/stdc++.h>

using namespace std;

int n, m;

bool visited[20005];

vector<int> adj_list[20005];
vector<int> adj_list_rev[20005];
int in_deg[20005];
stack<int> stk;

vector<int> comps[20005];
int belong_to[20005];
int num_comps = 0;

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
  belong_to[x] = num_comps;
  comps[num_comps].push_back(x);

  for (auto y : adj_list_rev[x]) {
    if (visited[y]) continue;
    Dfs2(y);
  }
}

void SCC() {
  for (int i = 1; i <= 2 * n; ++i) {
    if (visited[i]) continue;
    Dfs1(i);
  }

  for (int i = 1; i <= 2 * n; ++i) visited[i] = false;

  while (stk.size()) {
    int x = stk.top();
    stk.pop();

    if (visited[x]) continue;
    num_comps++;
    Dfs2(x);
  }
}

int Negate(int x) {
  if (x < 0) return -x;
  return x + n;
}

void Connect(int x, int y) {
  int neg_x = Negate(x);
  if (y < 0) y = -y + n;
  adj_list[neg_x].push_back(y);
  adj_list_rev[y].push_back(neg_x);
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

  SCC();

  bool ok = true;
  for (int i = 1; i <= n; ++i) {
    if (belong_to[i] == belong_to[i + n]) {
      ok = false;
    }
  }

  cout << (ok ? 1 : 0) << "\n";

  if (ok) {
    for (int i = 1; i <= n; ++i) {
      if (belong_to[i] < belong_to[i + n]) {
        cout << "0 ";
      } else {
        cout << "1 ";
      }
    }
    cout << "\n";
  }

  return 0;
}