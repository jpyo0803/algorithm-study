// 가장 가까운 공통 조상
// https://www.acmicpc.net/problem/3584

#include <bits/stdc++.h>

using namespace std;

int t, n, a, b;

vector<int> adj_list[10005];
int depth[10005];
int p[10005];

void Construct(int x, int d) {
  depth[x] = d;
  for (auto y : adj_list[x]) {
    Construct(y, d + 1);
  }
}

int Solve(int x, int y) {
  while (depth[x] < depth[y]) y = p[y];
  while (depth[x] > depth[y]) x = p[x];

  if (x == y) return x;

  while (p[x] != p[y]) {
    x = p[x];
    y = p[y];
  }

  return p[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      adj_list[i].clear();
      depth[i] = 0;
      p[i] = -1;
    }
    
    for (int i = 0; i < n - 1; ++i) {
      cin >> a >> b;
      adj_list[a].push_back(b);
      p[b] = a;
    } 

    int root;
    for (int i = 1; i <= n; ++i) {
      if (p[i] == -1) root = i;
    }

    Construct(root, 0);

    cin >> a >> b;

    cout << Solve(a, b) << "\n";
  }

  return 0;
}