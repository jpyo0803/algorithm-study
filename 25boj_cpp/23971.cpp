// ZOAC 4
// https://www.acmicpc.net/problem/23971

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int h, w, n, m;

  cin >> h >> w >> n >> m;

  int h_cnt = h / (1 + n);
  int w_cnt = w / (1 + m);

  if (h % (1 + n) != 0) {
    h_cnt++;
  }
  if (w % (1 + m) != 0) {
    w_cnt++;
  }

  cout << (long long)h_cnt * w_cnt << "\n";

  return 0;
}