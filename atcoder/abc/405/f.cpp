// F - Chord Crossing (ABC)
// https://atcoder.jp/contests/abc405/tasks/abc405_f

#include <bits/stdc++.h>

using namespace std;

int arr[2000005];

int n, m, q, a, b, c, d;
int depth[200005];
int id[2000005];
int cov[2000005];

int par[20][200005];

void PreCompute() {
  for (int k = 1; k <= 18; ++k) {
    for (int i = 1; i <= m; ++i) {
      par[k][i] = par[k - 1][par[k - 1][i]];
    }
  }
}

int LCA(int c, int d) {
  int u = cov[c], v = cov[d];
  int du = depth[u], dv = depth[v];
  int diff = du - dv;
  if (diff < 0) {
    swap(u, v);
    diff = -diff;
  }
  // du >= dv

  int i = 0;
  int tmpdiff = diff;
  while (tmpdiff > 0) {
    if (tmpdiff & (1 << i)) {
      u = par[i][u];
      tmpdiff ^= (1 << i);
    }
    i++;
  }

  if (u == v) return diff;

  for (int k = 18; k >= 0; --k) {
    if (par[k][u] == par[k][v]) continue;
    u = par[k][u];
    v = par[k][v];
  }

  int lca = depth[par[0][u]];  
  return du + dv - 2 * lca;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  for (int i = 1; i <= m; ++i) {
    cin >> a >> b;
    id[a] = id[b] = i;
  }

  stack<int> stk; // hold id
  stk.push(0); 
  for (int i = 1; i <= 2 * n; ++i) {
    if (i & 0b1) { // for query
      cov[i] = stk.top();
    } else {
      if (id[i] == 0) continue;
      if (stk.top() == id[i]) {
        stk.pop();
        depth[id[i]] = stk.size();
        par[0][id[i]] = stk.top();
      } else {
        stk.push(id[i]);
      }
    }
  }

  PreCompute();

  cin >> q;

  while (q--) {
    cin >> c >> d;
    cout << LCA(c, d) << "\n";
  }

  return 0;
}