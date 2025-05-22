// Bovine Genomics (Bronze)
// https://www.acmicpc.net/problem/14531

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> m;
  vector<string> sv(n), pv(n);
  for (int i = 0; i < n; ++i) cin >> sv[i];
  for (int i = 0; i < n; ++i) cin >> pv[i];

  int ans = 0;
  for (int i = 0; i < m; ++i) {
    bool a1, c1, g1, t1, a2, c2, g2, t2;
    a1 = c1 = g1 = t1 = a2 = c2 = g2 = t2 = false;
    for (int j = 0; j < n; ++j) {
      if (sv[j][i] == 'A') a1 = true;
      else if (sv[j][i] == 'C') c1 = true;
      else if (sv[j][i] == 'G') g1 = true;
      else if (sv[j][i] == 'T') t1 = true;
    }    
    for (int j = 0; j < n; ++j) {
      if (pv[j][i] == 'A') a2 = true;
      else if (pv[j][i] == 'C') c2 = true;
      else if (pv[j][i] == 'G') g2 = true;
      else if (pv[j][i] == 'T') t2 = true;
    }

    bool ok = true;
    if (a1 && a2) ok = false;
    if (c1 && c2) ok = false;
    if (g1 && g2) ok = false;
    if (t1 && t2) ok = false;
    if (ok) ans++;
  }

  cout << ans << "\n";

  return 0;
}