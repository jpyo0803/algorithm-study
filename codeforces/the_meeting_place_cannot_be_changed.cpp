// The Meeting Place Cannot Be Changed
// https://codeforces.com/contest/782/problem/B

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
int x[60005];
int v[60005];

double F(double m) {
  double ma = 0;
  for (int i = 0; i < n; ++i) {
    ma = max(ma, abs(m - x[i]) / v[i]);
  }
  return ma;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < n; ++i) cin >> v[i];

  double lo = 1, hi = 1e9;
  while (lo + 0.000001 < hi) {
    double p = (hi + lo * 2) / 3;
    double q = (hi * 2 + lo) / 3;

    double f1 = F(p);
    double f2 = F(q);

    if (f1 > f2) {
      lo = p;
    } else {
      hi = q;
    }
  }

  cout.precision(9);
  cout << fixed << F(lo) << "\n";

  return 0;
}