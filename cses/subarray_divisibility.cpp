// Subarray Divisibility
// https://cses.fi/problemset/task/1662

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n;
ll cnt[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cnt[0] = 1;

  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    sum += a;
    ll r = ((sum % n) + n) % n;
    cnt[r]++;
  }
  
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += cnt[i] * (cnt[i] - 1) / 2;
  }

  cout << ans << "\n";

  return 0;
}