// 회전하는 큐
// https://www.acmicpc.net/problem/1021

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  deque<int> dq;
  for (int i = 1; i <= N; ++i) {
    dq.push_back(i);
  }

  int ans = 0;
  for (int i = 0; i < M; ++i) {
    int x;
    cin >> x;

    int l = 0;
    for (auto e : dq) {
      if (e == x) break;
      l++;
    }

    int r = dq.size() - l;
    if (l < r) {
      ans += l;
      while (l--) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      ans += r;
      while (r--) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }

    dq.pop_front();
  }

  cout << ans << "\n";

  return 0;
}