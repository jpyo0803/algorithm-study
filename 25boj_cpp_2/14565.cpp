// 역원(Inverse) 구하기
// https://www.acmicpc.net/problem/14565

#include <bits/stdc++.h>

using namespace std;

long long n, a;

pair<long long, pair<long long, long long>> EEA(long long a, long long b, pair<long long, long long> x, pair<long long, long long> y) {
  if (b == 0) return {a, x};
  long long q = a / b; // q <= a
  long long r = a - q * b; // r <= a
  
  pair<long long, long long> next_y(x.first - q * y.first, x.second - q * y.second);
  return EEA(b, r, y, next_y);
}

pair<long long, pair<long long, long long>> EEA(long long a, long long b) {
  return EEA(a, b, {1, 0}, {0, 1});
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> a; // a < n <= 1e12

  auto result = EEA(a, n);
  long long g = result.first;
  long long s = result.second.first;

  cout << n - a << " "; // additive inverse a < n
  if (g != 1) cout << "-1\n";  
  else cout << (s < 0 ? s + n : s)  << "\n";

  return 0;
}