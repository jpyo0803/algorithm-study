// 최종 순위
// https://www.acmicpc.net/problem/3665

#include <bits/stdc++.h>

using namespace std;

int t, n, m;

bool adj_mat[505][505];
bool visited[505];
bool finished[505];

void SayImpossible() { cout << "IMPOSSIBLE\n"; }
void SayQM() { cout << "?\n"; }

bool Dfs(int x) {
  visited[x] = true;

  for (int y = 1; y <= n; ++y) {
    if (adj_mat[x][y] == false) continue;

    if (visited[y] == false) {
      return Dfs(y);
    } else if (finished[y] == false) {
      return true;
    }
  }

  finished[x] = true;
  return false;
}

void Toposort(vector<int>& ans, int x) {
  if (visited[x]) return;
  visited[x] = true;

  for (int y = 1; y <= n; ++y) {
    if (adj_mat[x][y] == false) continue;
    Toposort(ans, y);
  }
  ans.push_back(x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n;

    // reset
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        adj_mat[i][j] = false;
      }
    }

    vector<int> vv(n);
    for (int i = 0; i < n; ++i) cin >> vv[i];

    // construct adj mat
    for (int i = 0; i < n - 1; ++i) {
      int u = vv[i];
      for (int j = i + 1; j < n; ++j) {
        int v = vv[j];
        adj_mat[u][v] = true;
      }
    }

    cin >> m;

    bool ok = true;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;

      swap(adj_mat[a][b], adj_mat[b][a]);
    }
    if (ok == false) {
      SayImpossible();
      continue;
    }

    // find only out edge
    vector<int> out_cnt(n + 1, 0);
    vector<int> in_cnt(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
      for (int v = 1; v <= n; ++v) {
        if (u == v) continue;
        if (adj_mat[u][v]) out_cnt[u]++;
        if (adj_mat[v][u]) in_cnt[u]++;
      }
    }

    int num_only_out = 0;
    int s = -1;
    bool is_cycle = false;

    for (int i = 1; i <= n; ++i) {
      visited[i] = finished[i] = false;
    }

    for (int i = 1; i <= n; ++i) {
      if (out_cnt[i] > 0 && in_cnt[i] == 0) {
        num_only_out++;
        s = i;
        if (visited[s] == false) {
          is_cycle |= Dfs(s);
        }
      }
    }

    if (s == -1 || is_cycle) {
      SayImpossible();
      continue;
    }

    if (num_only_out > 1) {
      // if more than two only out nodes, it is partial order so say ?
      SayQM();
      continue;
    }

    for (int i = 1; i <= n; ++i) visited[i] = false;
    vector<int> ans;
    Toposort(ans, s);
    for (int i = ans.size() - 1; i >= 0; i--) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}