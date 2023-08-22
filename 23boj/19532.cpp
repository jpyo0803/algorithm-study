// 수학은 비대면강의입니다
// https://www.acmicpc.net/problem/19532

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  bool ok = true;
  for (int x = -999; x <= 999 && ok; ++x) {
    for (int y = -999; y <= 999 && ok; ++y) {
      if (a * x + b * y == c && d * x + e * y == f) {
        cout << x << " " << y << "\n";
        ok = false;
      }
    }
  }

  return 0;
}