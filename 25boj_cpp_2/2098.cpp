// 외판원 순회
// https://www.acmicpc.net/problem/2098

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[16][1 << 16];
int w[16][16];

int Solve(int u, int state) {
  if (state == ((1 << n) - 1)) {
    return w[u][0] == 0 ? 1e9 : w[u][0];
  }

  if (dp[u][state] != -1) return dp[u][state];

  int ret = 1e9;
  for (int v = 0; v < n; ++v) {
    if ((state >> v) & 0b1) continue;
    if (w[u][v] == 0) continue;
    ret = min(ret, Solve(v, state | (1 << v)) + w[u][v]);
  }

  dp[u][state] = ret;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      dp[i][j] = -1;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> w[i][j];
    }
  }

  int ans = 1e9;

  cout << Solve(0, 1) << "\n";

  return 0;
}