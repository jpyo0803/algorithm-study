// 합성함수와 쿼리
// https://www.acmicpc.net/problem/17435

#include <bits/stdc++.h>

using namespace std;

int m, q;
int p[200005][20]; // 2^19 = 524288

void PrecomputeTable() {
  // p[j][i] = p[p[j][i - 1]][i - 1]
  for (int i = 2; i < 20; ++i) {
    for (int j = 1; j <= m; ++j) {
      p[j][i] = p[p[j][i - 1]][i - 1];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m;
  for (int i = 1; i <= m; ++i) cin >> p[i][1];

  // precompute 
  PrecomputeTable();

  cin >> q;
  while (q--) { // 200000
    int n, x;
    cin >> n >> x;

    int f = 0;
    while ((1 << f) <= n) {
      if ((n >> f) & 0b1) {
        x = p[x][f + 1];
      }
      f++;
    }
    cout << x << "\n";
  }

  return 0;
}