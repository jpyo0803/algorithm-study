// B - Product Calculator (ABC)
// https://atcoder.jp/contests/abc406/tasks/abc406_b

#include <bits/stdc++.h>

using namespace std;

int n, k;
long long a;

long long Pow(int b, int e) {
  if (e == 0) return 1;
  long long res = Pow(b, e / 2);
  res *= res;
  if (e % 2) res *= b;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  long long c = Pow(10, k) - 1;

  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    cin >> a;

    if (ans > (c / a)) ans = 1;
    else ans *= a;
  }

  cout << ans << "\n";

  return 0;
}