// Maximum Median
// https://codeforces.com/contest/1201/problem/C

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int Solve(const vector<int>& v, ll lo, ll hi, function<bool(int)> f) {
  lo--;
  while (lo < hi) {
    ll mid = lo + 1 + (hi - (lo + 1)) / 2;
    if (f(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> av(n);
  for (auto& e : av) cin >> e;
  sort(av.begin(), av.end());

  cout << Solve(av, 1, av[n / 2] + k, [&](ll x) {
    ll sum = 0;
    for (int i = n / 2; i < n; ++i) {
      if (x > av[i]) sum += x - av[i];
    }
    return k >= sum;
  }) << "\n";

  return 0;
}