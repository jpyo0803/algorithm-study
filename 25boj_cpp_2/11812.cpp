// K진 트리
// https://www.acmicpc.net/problem/11812

#include <bits/stdc++.h>

using namespace std;

long long n, x, y;
int k, q;

long long D(long long x) {
  long long f = 1;
  long long s = 1;
  long long d = 0;
  while (s < x + 1) {
    f *= k;
    s += f;
    d++;
  }
  return d;
}

long long P(long long c) { return (c - 1) / k; }

long long Solve(long long x, long long y) {
  if (k == 1) {
    return abs(x - y);
  }

  long long xd = D(x), yd = D(y);
  long long ret = xd + yd;

  while (xd != yd) {
    if (xd < yd) {
      y = P(y);
      yd--;
    } else {
      x = P(x);
      xd--;
    }
  }

  while (x != y) {
    x = P(x), y = P(y);
    xd--, yd--;
  }
  ret -= xd * 2;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> k >> q;

  while (q--) {
    cin >> x >> y;
    x--, y--;
    cout << Solve(x, y) << "\n";
  }

  return 0;
}