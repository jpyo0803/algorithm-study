// 보물 지도
// https://www.acmicpc.net/problem/29332

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  long long l = -2e9, b = -2e9, t = 2e9, r = 2e9;
  for (int i = 0; i < N; ++i) {
    long long x, y;
    char d;
    cin >> x >> y >> d;
    if (d == 'L') {
      r = min(r, x);
    } else if (d == 'R') {
      l = max(l, x);
    } else if (d == 'D') {
      t = min(t, y);
    } else if (d == 'U') {
      b = max(b, y);
    }
  }

  if (l == -2e9 || b == -2e9 || t == 2e9 || r == 2e9) {
    cout << "Infinity\n";
  } else {
    cout << ((r - l - 1) * (t - b - 1)) << "\n";
  }

  return 0;
}