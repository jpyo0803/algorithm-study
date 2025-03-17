// 1의 개수 세기
// https://www.acmicpc.net/problem/9527

#include <bits/stdc++.h>

using namespace std;

long long a, b;

long long Count(long long n) {
  long long cnt = 0;

  long long nn = n;
  long long c = 2;
  while (nn) {
    long long q = (n + 1) / c;
    long long r = (n + 1) % c;
    // cout << q << " / " << r << endl;

    cnt += q * (c / 2);
    cnt += max(r - c / 2, 0LL);

    nn >>= 1;
    c <<= 1;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> a >> b;

  // Count(b);
  long long ans = Count(b) - Count(a - 1);
  cout << ans << "\n";

  return 0;
}