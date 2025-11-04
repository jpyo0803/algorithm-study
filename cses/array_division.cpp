// Array Division
// https://cses.fi/problemset/task/1085

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> xv(n);
  for (auto& e : xv) cin >> e;

  ll lo = 0, hi = 1e16;
  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;

    ll sum = 0;
    int gc = 1;
    for (auto e : xv) {
      if (sum + e > mid) {
        sum = e;
        if (sum > mid) {
          gc = 1e9;
          break;
        }
        gc++;
      } else {
        sum += e;
      }
    }
    if (gc <= k) {
      // possible
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << hi << "\n";

  return 0;
}