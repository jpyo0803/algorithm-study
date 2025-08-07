// 성 지키기
// https://www.acmicpc.net/problem/1236

#include <bits/stdc++.h>

using namespace std;

int n, m;
bool row[55];
bool col[55];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++ j) {
      char x;
      cin >> x;
      if (x == '.') continue;
      row[i] = col[j] = true;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (row[i]) continue;
    for (int j = 0; j < m; ++j) {
      if (col[j]) continue;
      row[i] = col[j] = true;
      ans++;
      break;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (row[i]) continue;
    ans++;
  }
  for (int i = 0; i < m; ++i) {
    if (col[i]) continue;
    ans++;
  }
  cout << ans << "\n";

  return 0;
}