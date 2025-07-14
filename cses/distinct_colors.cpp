// Distinct Colors
// https://cses.fi/problemset/task/1139

#include <bits/stdc++.h>

using namespace std;

int n;
set<int> colors[200005];

vector<int> adj_list[200005];
int ans[200005];

void Solve(int x, int p) {
  for (auto y : adj_list[x]) {
    if (y == p) continue;
    Solve(y, x);

    if (colors[x].size() < colors[y].size()) {
      swap(colors[x], colors[y]);
    }

    for (auto z : colors[y]) {
      colors[x].insert(z);
    }
    colors[y].clear();
  }
  ans[x] = colors[x].size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> c;
    colors[i].insert(c);
  }
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  Solve(1, -1);

  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  cout << "\n";

  return 0;
}