// C - GCD on Blackboard (ABC)
// https://atcoder.jp/contests/abc125/tasks/abc125_c

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int Gcd(int x, int y) {
  if (y == 0) return x;
  return Gcd(y, x % y);
}

int L[100005];
int R[100005];
int A[100005];

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  for (int i = 1; i <= n; ++i) {
    L[i] = Gcd(A[i], L[i - 1]);
  }
  for (int i = n; i >= 1; --i) {
    R[i] = Gcd(A[i], R[i + 1]);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == 1) ans = max(ans, R[2]);
    else if (i == n) ans = max(ans, L[n - 1]);
    else ans = max(ans, Gcd(L[i - 1], R[i + 1]));
  }
  cout << ans << "\n";

  return 0;
}