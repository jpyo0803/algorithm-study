// 등산 마니아 
// https://www.acmicpc.net/problem/20188

#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> adj_list[300010];

bool visited[300010];

long long ans = 0;

int Dfs(int u, int depth) {
  visited[u] = true;

  ans += (long long)depth * (n - 1);

  int sum = 0;
  for (auto v : adj_list[u]) {
    if (visited[v] == false) {
      int cc = Dfs(v, depth + 1);
      ans -= (long long) sum * cc * depth;
      sum += cc;
    }
  }

  ans -= (long long)sum * depth;
  return sum + 1;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  Dfs(1, 0);

  cout << ans << "\n";

  return 0;
}