// Chess Tournament
// https://www.acmicpc.net/problem/13344

#include <bits/stdc++.h>

using namespace std;

int n, m;

int p[50005];

int UF(int x) {
  if (x == p[x]) return x;
  return p[x] = UF(p[x]); 
}

set<int> adj_list[50005]; // to remove duplicates

bool visited[50005];
bool finished[50005];
bool Solve(int x) {
  visited[x] = true;

  for (auto y : adj_list[x]) {
    if (visited[y] == false) {
      if (Solve(y) == false) {
        return false;
      }
    } else if (/*visited==true*/finished[y] == false) {
      // cycle
      return false;
    }
  }
  finished[x] = true;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) p[i] = i;
  
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    char comp;
    int k, l;
    cin >> k >> comp >> l;
    if (comp == '>') {
      edges.emplace_back(k, l);
    } else {
      int a = UF(k);
      int b = UF(l);
      if (a != b) {
        p[b] = a;
      }
    }
  }

  for (auto& edges : edges) {
    int u = UF(edges.first);
    int v = UF(edges.second);
    if (u == v) {
      cout << "inconsistent\n";
      return 0;
    }

    auto it = adj_list[u].find(v);
    if (it == adj_list[u].end()) {
      adj_list[u].insert(v);
    }
  }

  bool ans = true;
  for (int i = 0; i < n; ++i) {
    if (visited[i]) continue;
    ans &= Solve(i);
  }

  cout << (ans ? "consistent" : "inconsistent") << "\n";

  return 0;
}