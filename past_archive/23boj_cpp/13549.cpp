// 숨바꼭질 3
// https://www.acmicpc.net/problem/13549

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  vector<bool> chk(100010, false);
  deque<pair<int, int>> dq;
  dq.emplace_back(0, N);

  chk[N] = true;

  while (dq.empty() == false) {
    auto e = dq.front();
    dq.pop_front();

    int t = e.first;
    int pos = e.second;

    if (pos == K) {
      cout << t << "\n";
      break;
    }

    if (pos * 2 <= 100000 && chk[pos * 2] == false) {
      chk[pos * 2] = true;
      dq.emplace_front(t, pos * 2);
    }
    if (pos - 1 >= 0 && chk[pos - 1] == false) {
      chk[pos - 1] = true;
      dq.emplace_back(t + 1, pos - 1);
    }
    if (pos + 1 <= 100000 && chk[pos + 1] == false) {
      chk[pos + 1] = true;
      dq.emplace_back(t + 1, pos + 1);
    }
  }

  return 0;
}