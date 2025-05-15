// Speeding Ticket (Bronze)
// https://www.acmicpc.net/problem/11971

#include <bits/stdc++.h>

using namespace std;

int n, m;

pair<int, int>
    n_arr[105];  // positive integer number guarantees # segments <= 100
pair<int, int> m_arr[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> n_arr[i].first >> n_arr[i].second;
  for (int i = 0; i < m; ++i) cin >> m_arr[i].first >> m_arr[i].second;

  int ans = 0;

  int i = -1, j = -1;
  int pos_i = 0, pos_j = 0;

  while (true) {
    if (pos_i < pos_j) {
      i++;
      pos_i += n_arr[i].first;
      ans = max(ans, max(0, m_arr[j].second - n_arr[i].second));
    } else if (pos_i > pos_j) {
      j++;
      pos_j += m_arr[j].first;
      ans = max(ans, max(0, m_arr[j].second - n_arr[i].second));
    } else {  // break tie
      // if i == n-1 && j == m-1, then finish
      if (i == n - 1 && j == m - 1)
        break;
      else
        pos_i += n_arr[++i].first;
    }
  }

  cout << ans << "\n";

  return 0;
}