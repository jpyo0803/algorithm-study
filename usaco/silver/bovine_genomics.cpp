// Bovine Genomics (Silver)
// https://www.acmicpc.net/problem/14528

/*
  한 그룹으로 부터 생성한 N개의 element group 다른 그룹으로 부터 생성한 N개의 element group
  이 disjoint한지 판별하는 알고리즘을 O(N)에 가능하게 하는 것이 관건.

  이 문제에서는 이것이 가능한 이유가 세개의 position으로 부터 얻은 value의 순서 있는 합성이 가질 수 있는
  가능한 가지 수가 작아서 가능
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;

int GetIdx(char c) {
  if (c == 'A')
    return 0;
  else if (c == 'C')
    return 1;
  else if (c == 'G')
    return 2;
  return 3;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  vector<string> sv(n), pv(n);
  for (int i = 0; i < n; ++i) cin >> sv[i];
  for (int i = 0; i < n; ++i) cin >> pv[i];

  int ans = 0;

  for (int i = 0; i < m - 2; ++i) {
    for (int j = i + 1; j < m - 1; ++j) {
      for (int k = j + 1; k < m; ++k) {
        bool record[64]{};
        for (int l = 0; l < n; ++l) {
          int p = 4 * 4 * GetIdx(sv[l][i]) + 4 * GetIdx(sv[l][j]) +
                  GetIdx(sv[l][k]);
          record[p] = true;
        }

        bool ok = true;
        for (int l = 0; l < n; ++l) {
          int p = 4 * 4 * GetIdx(pv[l][i]) + 4 * GetIdx(pv[l][j]) +
                  GetIdx(pv[l][k]);
          if (record[p]) ok = false;
        }
        if (ok) ans++;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}