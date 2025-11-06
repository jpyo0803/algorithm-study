// Mahmoud and Ehab and the function
// https://codeforces.com/contest/862/problem/E

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll Solve(const vector<ll>& v, ll x) {
  int lo = 0, hi = v.size() - 1;

  ll ret = 1e19;
  while (lo <= hi) {
    int m = (lo + hi) / 2;

    ret = min(ret, abs(x + v[m]));
    if (x + v[m] < 0) {
      lo = m + 1;
    } else {
      hi = m - 1;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  vector<ll> av(n), bv(m);
  for (auto& e : av) cin >> e;
  for (auto& e : bv) cin >> e;

  ll a_sum = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0)
      a_sum += av[i];
    else
      a_sum -= av[i];
  }

  ll b_sum = 0;
  vector<ll> b_sums;
  for (int i = 0; i < m; ++i) {
    if (i % 2 == 0)
      b_sum -= bv[i];
    else
      b_sum += bv[i];
    if (i >= n - 1) {
      int start_idx = i - n + 1;
      b_sums.push_back((start_idx % 2 == 0) ? b_sum : -b_sum);
      if (start_idx % 2 == 0) {
        b_sum += bv[start_idx];
      } else {
        b_sum -= bv[start_idx];
      }
    }
  }

  sort(b_sums.begin(), b_sums.end());

  cout << Solve(b_sums, a_sum) << "\n";

  ll acc = 0;
  while (q--) {
    int l, r;
    ll x;
    cin >> l >> r >> x;
    if ((r - l) % 2 == 0) {
      if (r % 2)
        acc += x;
      else
        acc -= x;
    }
    cout << Solve(b_sums, a_sum + acc) << "\n";
  }

  return 0;
}