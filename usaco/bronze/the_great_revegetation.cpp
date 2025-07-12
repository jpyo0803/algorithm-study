// The Great Revegetation (Bronze)
// https://www.acmicpc.net/problem/17040

#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int, int> edges[155];
int color[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].first >> edges[i].second;
    if (edges[i].first > edges[i].second) swap(edges[i].first, edges[i].second);
  }

  for (int i = 1; i <= n; ++i) {
    bool used[5]{};
    for (int j = 0; j < m; ++j) {
      int a, b;
      tie(a, b) = edges[j];
      if (i == b && color[a] != 0) {
        used[color[a]] = true;
      }
    }
    for (int j = 1; j <= 4; ++j) {
      if (used[j] == false) {
        color[i] = j;
        break;
      }
    }
    cout << color[i];
  }

  return 0;
}