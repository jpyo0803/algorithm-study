// 이항 계수 3
// https://www.acmicpc.net/problem/11401

/*
    (n, k) = (n ... n-k+1) / k!
    avoid Overflow and Floating
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int pmod = 1e9 + 7;

int n, k;

long long FLT(int a, int p) {
  if (p == 0) return 1;
  long long ret = FLT(a, p / 2);
  ret *= ret;
  ret %= pmod;
  if (p % 2 == 1) {
    ret *= a;
    ret %= pmod;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  long long num, den;
  num = den = 1LL;

  for (int i = n - k + 1; i <= n; ++i) {
    num *= i;
    num %= pmod;
  }
  for (int i = 1; i <= k; ++i) {
    den *= i;
    den %= pmod;
  }

  long long den_inv = FLT(den, pmod - 2);
  long long ans = (num * den_inv) % pmod;

  cout << ans << "\n";

  return 0;
}