// F - Sock 4 (ABC)
// https://atcoder.jp/contests/abc412/tasks/abc412_f

#include <bits/stdc++.h>

using namespace std;

int n, c;

constexpr int kMod = 998244353;

long long ModPow(int base, int exp) {
  if (exp == 0) return 1;
  long long res = ModPow(base, exp / 2);
  res *= res;
  res %= kMod;
  if (exp % 2) res *= base;
  res %= kMod;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> c;
  c--;

  int s = 0;
  vector<int> av(n);
  for (int i = 0; i < n; ++i) {
    cin >> av[i];
    s += av[i];
  }
  av[c]++;

  int cnt = av[c];  // use 'cnt' to find correct dp

  sort(av.begin(), av.end());

  vector<int> dp(n + 10, 0);
  vector<int> prob(n + 10);

  int inv_s = ModPow(s, kMod - 2);
  long long left = 0, right = 0;
  for (int i = 0; i < n; ++i) {
    prob[i] = ((long long)av[i] * inv_s) % kMod;
    left += prob[i];
    left %= kMod;
  }

  for (int i = n - 1; i >= 0; --i) {
    right += (long long)prob[i + 1] * dp[i + 1];
    right %= kMod;
    left -= prob[i] + kMod;
    left %= kMod;

    long long num = (1 + right) % kMod;
    long long den = (1 - left + kMod) % kMod;
    dp[i] = (num * ModPow(den, kMod - 2)) % kMod;
  }

  for (int i = 0; i < av.size(); ++i) {
    if (av[i] == cnt) {
      cout << dp[i] << "\n";
      return 0;
    }
  }

  return 0;
}