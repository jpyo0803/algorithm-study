// LCA 2
// https://www.acmicpc.net/problem/11438

#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;

vector<int> adj_list[100005];
int p[100005][20];
int d[100005];
int pow2_dp[20];

void Dfs(int x, int parent, int depth) {
  p[x][0] = parent;
  d[x] = depth;
  for (auto y : adj_list[x]) {
    if (y == parent) continue;
    Dfs(y, x, depth + 1);
  }
}

int Pow2(int exp) {
  if (exp == 0) return 1;
  if (pow2_dp[exp] != 0) return pow2_dp[exp];

  int res = Pow2(exp / 2);
  res *= res;
  if (exp % 2) {
    res *= 2;
  }
  pow2_dp[exp] = res;
  return res;
}

void PreProc() {
  Dfs(1, 0, 0);  // -1 means no parent

  // p[x][i] = node x's 2^i -th parent
  // p[x][i] = p[p[x][i-1]][i-1]

  for (int i = 1; i <= 18; ++i) {
    for (int x = 1; x <= n; ++x) {
      int ancestor = p[x][i - 1];
      if (ancestor == 0) continue;
      p[x][i] = p[ancestor][i - 1];
    }
  }
}

int Solve(int a, int b) {
  if (d[a] < d[b]) {
    swap(a, b);
  }
  // invariant a >= b
  // make them at same level
  for (int i = 18; i >= 0; --i) {
    if (d[a] - d[b] >= Pow2(i)) {
      a = p[a][i];
    }
  }

  assert(d[a] == d[b]);
  if (a == b) return a;

  for (int i = 18; i >= 0; --i) {
    if (p[a][i] != p[b][i]) {
      a = p[a][i], b = p[b][i];
    }
  }

  return p[a][0];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  PreProc();

  cin >> m;
  while (m--) {
    cin >> a >> b;
    cout << Solve(a, b) << "\n";
  }

  return 0;
}