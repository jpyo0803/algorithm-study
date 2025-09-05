// E - Popcount Sum 3 (ABC)
// https://atcoder.jp/contests/abc406/tasks/abc406_e

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int t, k;
ll n;

ll f[62][62];
ll s[62][62];

constexpr ll kMod = 998244353;

ll Pow(ll base, ll exp) {
  if (exp == 0) return 1;
  ll res = Pow(base, exp / 2);
  res *= res;
  res %= kMod;
  if (exp % 2) res *= base;
  res %= kMod;
  return res;
}

void Pre() {
  // f(i, j) = f(i - 1, j - 1) + f(i - 1, j)
  // s(i, j) = s(i - 1, j) + s(i - 1, j - 1) + 2^(i - 1) * f(i - 1, j - 1)

  f[0][0] = 1;
  for (int i = 0; i <= 60; ++i) {
    for (int j = 0; j <= i; ++j) {
      f[i + 1][j + 1] += f[i][j];
      f[i + 1][j + 1] %= kMod;
      f[i + 1][j] += f[i][j];
      f[i + 1][j] %= kMod;

      s[i + 1][j] += s[i][j];
      s[i + 1][j] %= kMod;
      s[i + 1][j + 1] += s[i][j];
      s[i + 1][j + 1] %= kMod;
      s[i + 1][j + 1] += (Pow(2, i) * f[i][j]) % kMod;
      s[i + 1][j + 1] %= kMod;
    }
  }
}

ll Solve(ll n, int k) {
  vector<int> d;
  while (n) {
    d.push_back(n & 1);
    n >>= 1;
  }

  ll offset = 0;
  int c = 0;
  ll ans = 0;

  for (int i = d.size() - 1; i >= 0; --i) {
    if (d[i] == 1) {
      if (c <= k) {
        ans += s[i][k - c];
        ans %= kMod;

        ans += (offset * f[i][k - c]) % kMod;
        ans %= kMod;

      }
      offset += Pow(2, i);
      offset %= kMod;

      c++;
    }
  }

  if (k == c) ans = (ans + offset) % kMod;

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Pre();

  cin >> t;
  while (t--) {
    cin >> n >> k;

    cout << Solve(n, k) << "\n";
  }

  return 0;
}