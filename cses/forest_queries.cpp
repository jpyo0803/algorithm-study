// Forest Queries
// https://cses.fi/problemset/task/1652

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, q;
int ps[1005][1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char ch;
      cin >> ch;
      ps[i + 1][j + 1] = (ch == '*') + ps[i][j + 1] + ps[i + 1][j] - ps[i][j];
    }
  }

  while (q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << (ps[y2][x2] - ps[y1 - 1][x2] - ps[y2][x1 - 1] + ps[y1 - 1][x1 - 1]) << "\n";
  }

  return 0;
}