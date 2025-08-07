// 책 페이지
// https://www.acmicpc.net/problem/1019

#include <bits/stdc++.h>

using namespace std;

int n;
long long ans[10];

void F(int x, int f) {
  while (x > 0) {
    ans[x % 10] += f;
    x /= 10;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  int f = 1;
  int cnt = 0;
  while (n >= 9) {
    while (n % 10 != 9) {
      F(n--, f);
    }
    n /= 10;
    long long cnt = (long long)(n + 1) * f;
    for (int i = 0; i < 10; ++i) ans[i] += cnt;
    ans[0] -= f;
    f *= 10;
  }

  while (n >= 1) F(n--, f);

  for (int i = 0; i < 10; ++i) cout << ans[i] << " ";

  return 0;
}