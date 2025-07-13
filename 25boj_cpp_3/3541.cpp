// 상근타워 
// https://www.acmicpc.net/problem/3541

#include <bits/stdc++.h>

using namespace std;

int n, m;

int Gcd(int x, int y) {
  if (y == 0) return x;
  return Gcd(y, x % y);
}

int Lcm(int x, int y) {
  int g = Gcd(x, y);
  return x * y / g;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  int ans = 2e9;
  for (int i = 0; i < m; ++i) {
    int u, d;
    cin >> u >> d;
    int lcm = Lcm(u, d);
    int f = lcm / u + lcm / d;
    int r = n % f;

    int s = 0;

    while (r--) {
      if (s - d > 0) s -= d;
      else s += u;
    } 

    if (s == 0) s = u + d;
    ans = min(ans, s);
  }

  cout << ans << "\n";

  return 0;
}