// Building Roads
// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool vis[100005];
vector<int> adj[100005];

int n, m;

void Dfs(vector<int>& v, int x) {
  vis[x] = true;
  v.push_back(x);
  for (auto y : adj[x]) {
    if (vis[y]) continue;
    Dfs(v, y);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<vector<int>> clusters;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    vector<int> v;
    vis[i] = true;
    Dfs(v, i);
    clusters.push_back(vector<int>());
    swap(clusters.back(), v);
  }

  cout << clusters.size() - 1 << "\n"; 
  for (int i = 0; i < clusters.size() - 1; ++i) {
    cout << clusters[i].back() << " " << clusters[i + 1][0] << "\n";
  }

  return 0;
}