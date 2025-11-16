// Minimizing Difference
// https://codeforces.com/contest/1244/problem/E

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
ll k;
ll lps[100005];  // work to be done to flatten up to a point
ll rps[100005];
vector<ll> a;

ll UpperBound(const vector<ll>& v, ll lo, ll hi, ll x) {
  hi++;

  while (lo < hi) {
    ll mid = lo + (hi - 1 - lo) / 2;
    if (v[mid] <= x) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

ll RevUpperBound(const vector<ll>& v, ll lo, ll hi, ll x) {
  lo--;

  while (lo < hi) {
    ll mid = lo + 1 + (hi - (lo + 1)) / 2;
    if (v[mid] >= x) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  return hi;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  a.resize(n);

  for (auto& e : a) cin >> e;
  sort(a.begin(), a.end());

  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    lps[i] = a[i] * (i + 1) - sum;
  }
  sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    sum += a[i];
    rps[i] = sum - a[i] * (n - i);
  }

  ll ans = 2e9;

  for (int i = 0; i < n; ++i) {
    ll lo = a[i], hi = 2e9;
    while (lo < hi) {
      ll mid = lo + (hi - lo) / 2;
      ll pos = UpperBound(a, i, n - 1, mid);
      ll extra = 0;
      if (pos < n) {
        extra = (a[pos] - mid) * (n - pos) + rps[pos];
      }
      ll total_work = lps[i] + extra;
      if (total_work <= k) {
        hi = mid;
        ans = min(ans, mid - a[i]);
      } else {
        lo = mid + 1;
      }
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    ll lo = -1, hi = a[i];
    while (lo < hi) {
      ll mid = lo + (hi - lo) / 2 + 1;
      ll pos = RevUpperBound(a, 0, i, mid);
      ll extra = 0;
      if (pos >= 0) {
        extra = (mid - a[pos]) * (pos + 1) + lps[pos];
      }
      ll total_work = rps[i] + extra;
      if (total_work <= k) {
        lo = mid;
        ans = min(ans, a[i] - mid);
      } else {
        hi = mid - 1;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}