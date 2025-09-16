// E - Fruit Lineup (ABC)
// https://atcoder.jp/contests/abc405/tasks/abc405_e

#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll kMod = 998244353; 

ll A, O, B, G;

ll Pow(ll base, ll exp) {
  if (exp == 0) return 1;
  ll res = Pow(base, exp / 2);
  res *= res;
  res %= kMod;
  if (exp % 2) res *= base;
  res %= kMod;
  return res;
}

ll ModInv(ll x) {
  return Pow(x, kMod - 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> A >> O >> B >> G;
  
  ll g_minus_1 = 1;
  ll o = 1;
  ll a = 1;
  for (int i = 1; i <= G - 1; ++i) {
    g_minus_1 *= i;
    g_minus_1 %= kMod;
  }
  for (int i = 1; i <= O; ++i) {
    o *= i;
    o %= kMod;
  }
  for (int i = 1; i <= A; ++i) {
    a *= i;
    a %= kMod;
  }
  
  ll n1 = 1, n2 = 1, d1 = 1, d2 = 1;
  for (int i = 1; i <= B + G - 1; ++i) {
    n1 *= i;
    n1 %= kMod;
  }
  for (int i = 1; i <= B; ++i) {
    d1 *= i;
    d1 %= kMod;
  }
  for (int i = 1; i <= O + A; ++i) {
    n2 *= i;
    n2 %= kMod;
  }
  d2 = a;

  ll ans = 1;
  ans = (ans * n1) % kMod;
  ans = (ans * n2) % kMod;
  ans = (ans * ModInv(d1)) % kMod;
  ans = (ans * ModInv(g_minus_1)) % kMod;
  ans = (ans * ModInv(d2)) % kMod;
  ans = (ans * ModInv(o)) % kMod;
  for (ll x = 1; x <= B; ++x) {
    // update
    n1 = (n1 * ModInv(B + G - 1 - (x - 1))) % kMod;
    n2 = (n2 * (A + O + x)) % kMod;
    d1 = (d1 * ModInv(B - (x - 1))) % kMod;
    d2 = (d2 * (A + x)) % kMod;

    ll f = 1;
    f = (f * n1) % kMod;
    f = (f * n2) % kMod;
    f = (f * ModInv(d1)) % kMod;
    f = (f * ModInv(g_minus_1)) % kMod;
    f = (f * ModInv(d2)) % kMod;
    f = (f * ModInv(o)) % kMod;

    ans += f;
    ans %= kMod;
  }
  cout << ans << "\n";

  return 0;
}