// 트리와 쿼리 2
// https://www.acmicpc.net/problem/13511

#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<pair<int, int>> adj_list[100005];

int p[100005][19];           // track ancestor
long long cost[100005][19];  // track cost

int depth[100005];

void Precompute() {
  
  
  for (int i = 2; i <= 17; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[j][i] = p[p[j][i - 1]][i - 1];
      cost[j][i] = cost[j][i - 1] + cost[p[j][i - 1]][i - 1];
    }
  }
}

void Dfs(int x, int prev, int d, int c) {
  depth[x] = d;
  p[x][1] = prev;  // node x's direct parent is prev
  cost[x][1] = c;
  for (auto [y, c] : adj_list[x]) {
    if (y == prev) continue;
    Dfs(y, x, d + 1, c);
  }
}

long long Solve1(int u, int v) {
  // return cost

  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  // WLOG, u is deeper or equal
  int diff = depth[u] - depth[v];

  long long u_cost = 0, v_cost = 0;

  int f = 0;
  while ((1 << f) <= diff) {
    if ((diff >> f) & 0b1) {
      u_cost += cost[u][f + 1];
      u = p[u][f + 1];
    }
    f++;
  }

  if (u == v) return u_cost;


  for (int i = 17; i >= 1; --i) {
    if (p[u][i] != p[v][i]) {
      // cout << "u / v : " << u << " / " << v << ", i : " << i << endl;
      u_cost += cost[u][i];
      v_cost += cost[v][i];
      u = p[u][i];
      v = p[v][i];
    }
  }
  // cout <<" before: " << u_cost << " / " << v_cost << endl;
  u_cost += cost[u][1];
  v_cost += cost[v][1];

  // cout << u_cost << " / " << v_cost << endl;

  return u_cost + v_cost;
}

int Solve2(int u, int v, int k) {
  // find distance based on depth along the LCA
  // 만약 dist(u, lca) <= k

  int uc = u, vc = v;
  int u_d = 0, v_d = 0;
  bool swapped = false;
  if (depth[u] < depth[v]) {
    swap(u, v);
    swapped = true;
  }

  // WLOG

  int diff = depth[u] - depth[v];
  int f = 0;
  while ((1 << f) <= diff) {
    if ((diff >> f) & 0b1) {
      u_d += (1 << f);
      u = p[u][f + 1];
    }
    f++;
  }

  if (u != v) {
    for (int i = 17; i >= 1; --i) {
      if (p[u][i] != p[v][i]) {
        u_d += (1 << (i - 1));
        v_d += (1 << (i - 1));
        u = p[u][i];
        v = p[v][i];
      }
    }

    u_d++, v_d++;
  }

  if (swapped) swap(u_d, v_d);

  u_d++, v_d++;
  int dist = u_d + v_d - 1;

  // cout << u_d << " / " << v_d << " / ";
  int ans;
  if (k <= u_d) {
    ans = uc;
    int f = 0;
    int diff = k - 1;
    // cout << " diff 1: " << diff << endl;
    while ((1 << f) <= diff) {
      if ((diff >> f) & 0b1) ans = p[ans][f + 1];
      f++;
    }
  } else {
    ans = vc;
    int f = 0;
    int diff = v_d - k + u_d - 1;
    // cout << " diff 2: " << diff << endl;
    while ((1 << f) <= diff) {
      if ((diff >> f) & 0b1) ans = p[ans][f + 1];
      f++;
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj_list[a].emplace_back(b, c);
    adj_list[b].emplace_back(a, c);
  }

  // set root = 1
  Dfs(1, -1, 0, 0);

  Precompute();

  cin >> m;
  while (m--) {
    int type, u, v, k;
    cin >> type >> u >> v;
    if (type == 1) {
      cout << Solve1(u, v) << "\n";
    } else {
      // type2
      cin >> k;
      cout << Solve2(u, v, k) << "\n";
    }
  }

  return 0;
}