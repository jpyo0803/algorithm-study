// Speeding Ticket
// http://www.usaco.org/index.php?page=viewproblem2&cpid=568

#include <bits/stdc++.h>

using namespace std;

int n, m;

int limits[100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  int pos = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < a; ++j) {
      limits[pos++] = b;
    }
  }

  pos = 0;

  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < a; ++j) {
      ans = max(ans, b - limits[pos++]);
    }
  }

  cout << ans << "\n";

  return 0;
}