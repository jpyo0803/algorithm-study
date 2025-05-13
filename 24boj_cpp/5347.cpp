// LCM
// https://www.acmicpc.net/problem/5347

#include <bits/stdc++.h>

using namespace std;

int GCD(int x, int y) {
  if (y == 0) return x;
  return GCD(y, x % y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    int m = GCD(a, b);
    cout << (long long)a * b / m << "\n";
  }

  return 0;
}