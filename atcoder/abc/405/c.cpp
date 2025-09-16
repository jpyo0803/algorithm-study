// C - Sum of Product (ABC)
// https://atcoder.jp/contests/abc405/tasks/abc405_c

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
ll a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  ll sum = 0;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    ans += sum * a;
    sum += a;
  }

  cout << ans << "\n";

  return 0;
}