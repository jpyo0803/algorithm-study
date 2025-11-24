// E - Handshake (ABC)
// https://atcoder.jp/contests/abc149/tasks/abc149_e

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, m;
vector<ll> a;
ll ps[200005]; // count larger or equal
ll ps2[200005];

ll UpperBound(ll lo, ll hi, ll x) {
  hi++;

  while (lo < hi) {
    ll mid = lo + (hi - 1 - lo) / 2;
    if (a[mid] > x) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  a.resize(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  sort(rbegin(a), rend(a));

  ll cnt = 0;
  for (ll i = 200000; i >= 0; --i) {
    while (cnt < n && a[cnt] >= i) cnt++;
    ps[i] = cnt;
  }

  for (ll i = 1; i <= n; ++i) {
    ps2[i] = ps2[i - 1] + a[i - 1];
  }
  
  ll lo = 0, hi = 2e5;
  
  ll max_x;
  while (lo <= hi) {
    ll x = (lo + hi) / 2;
    
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
      sum += x >= a[i] ? ps[x - a[i]] : n;
    }
    if (sum >= m) {
      max_x = x;
      lo = x + 1;
    } else if (sum < m) {
      hi = x - 1;
    }
  }

  ll ans = 0;


  cnt = 0;
  for (ll i = 0; i < n; ++i) {
    ll c = UpperBound(0, n - 1, max_x - a[i]);
    if (c >= 1) {
      cnt += c;
      ans += ps2[c] + (ll)a[i] * c;
    }
  }

  ans += (ll)(m - cnt) * max_x;
  cout << ans << "\n";

  return 0;
}