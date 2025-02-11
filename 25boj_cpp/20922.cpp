// 겹치는 건 싫어
// https://www.acmicpc.net/problem/20922

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  int ans = 0;

  vector<queue<int>> qv(100010);

  int curr_len = 0;

  int last_barrier = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    qv[x].push(i);

    if (qv[x].size() > k) {
      int pos_first = qv[x].front();
      qv[x].pop();
      if (last_barrier < pos_first) {
        curr_len = i - pos_first;
        last_barrier = pos_first;
      } else {
        curr_len++;
      }
    } else {
      curr_len++;
    }
    // cout << i << " / " << x << " / curr len : " << curr_len << endl;
    ans = max(ans, curr_len);
  }

  cout << ans << "\n";

  return 0;
}