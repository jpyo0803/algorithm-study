// 곱셈
// https://www.acmicpc.net/problem/1629

#include <bits/stdc++.h>

using namespace std;

long long Pow(long long a, long long b, long long c) {
  if (b == 0) return 1;
  long long x = Pow(a, b / 2, c);
  x *= x;
  x %= c;
  if (b % 2) x *= a;
  x %= c;
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long A, B, C;
  cin >> A >> B >> C;

  cout << Pow(A, B, C) << "\n";

  return 0;
}