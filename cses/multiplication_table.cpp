// Multiplication Table
// https://cses.fi/problemset/task/2422

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n;

ll F(ll x) {
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += min(x / i, n);
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  ll med = n * n / 2 + 1;
  ll lo = 1, hi = n * n;

  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;
    ll cnt = F(mid);  // less or equal
    if (cnt >= med) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo << "\n";

  return 0;
}