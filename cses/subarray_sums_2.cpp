// Subarray Sums II
// https://cses.fi/problemset/task/1661

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, x;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> x;

  ll sum = 0;
  map<ll, ll> pm;
  pm.insert({0, 1});

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    sum += a;
    ll other = sum - x;
    ans += pm[other];
    pm[sum]++;
  }

  cout << ans << "\n";

  return 0;
}