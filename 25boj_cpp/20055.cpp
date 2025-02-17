// 컨베이어 벨트 위의 로봇
// https://www.acmicpc.net/problem/20055

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  deque<pair<int, bool>> dq; // 내구도, 로봇 유무
  for (int i = 0; i < n * 2; ++i) {
    int x;
    cin >> x;
    dq.emplace_back(x, false);
  }

  int ans = 0;
  int broken_cnt = 0;

  while (broken_cnt < k) {
    auto b = dq.back();
    dq.pop_back();
    dq.push_front(b);
    if (dq[n - 1].second) {
      dq[n - 1].second = false;
      // unload robot
    }

    for (int i = n - 1; i >= 1; --i) {
      if (dq[i].second == false && dq[i].first >= 1 && dq[i - 1].second == true) {
        dq[i].second = true;
        dq[i].first--;
        if (dq[i].first == 0) broken_cnt++;
        dq[i - 1].second = false;
      }
    }
    if (dq[n - 1].second == true) {
      dq[n - 1].second = false;
    }

    if (dq[0].second == false && dq[0].first >= 1) {
      dq[0].second = true;
      dq[0].first--;
      if (dq[0].first == 0) broken_cnt++;
    }
    ans++;
  }

  cout << ans << "\n";

  return 0;
}