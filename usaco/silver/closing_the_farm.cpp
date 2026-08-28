// Closing the Farm (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=644

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
vector<int> adj[3005];
int vis[3005];
int close_cnt = -1;

int Dfs(int x) {
  if (vis[x] >= 1) return 0;
  vis[x] = 1;
  int ret = 1;
  for (auto y : adj[x]) {
    ret += Dfs(y);
  }
  return ret;
}

bool Solve(int c) {
  vis[c] = 2;
  close_cnt++;
  int start = -1;
  for (int i = 1; i <= n; ++i) {
    if (vis[i] == 2) continue;
    vis[i] = 0;
    if (start == -1) start = i;
  }
  return Dfs(start) == (n - close_cnt);
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);
  
  ifstream cin("closing.in");
  ofstream cout("closing.out");

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int c = 0;
  for (int i = 0; i < n; ++i) {
    cout << (Solve(c) ? "YES" : "NO") << "\n"; 
    cin >> c;
  }

  return 0;
}