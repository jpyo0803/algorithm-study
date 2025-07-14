// E - E [max] (ABC)
// https://atcoder.jp/contests/abc411/tasks/abc411_e

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 998244353;

long long Pow(long long base, long long exp) {
  if (exp == 0) return 1;
  long long res = Pow(base, exp / 2);
  res *= res;
  res %= kMod;
  if (exp % 2) res *= base;
  res %= kMod;
  return res;
}

long long InvMod(long long base) {
  return Pow(base, kMod - 2);
}

int n;
int arr[100005][6];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> v;
  v.reserve(n * 6);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      cin >> arr[i][j];
      v.push_back(arr[i][j]);
    }
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  int k = v.size();

  vector<vector<int>> d(k + 5); // keep who to update for each v_i
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      int idx = lower_bound(v.begin(), v.end(), arr[i][j]) - v.begin();
      d[idx].push_back(i); // it means when at v[idx], dice 'i' gets affected
    }
  }

  long long p = 1;
  vector<int> cnt(n, 0);
  int zero_cnt = n;
  long long ans = 0;
  int valid_cnt = 0;

  for (int i = 0; i < k; ++i) {
    long long last_p = p;
    for (auto e : d[i]) {
      if (cnt[e] == 0) {
        zero_cnt--;
      } else {
        p = (p * InvMod(cnt[e])) % kMod; // cancel previous one, always divisible
      }
      cnt[e]++; // this can be max 6
      p = (p * cnt[e]) % kMod; // multiply updated one
    }

    if (zero_cnt == 0) {
      valid_cnt++;
      if (valid_cnt == 1) {
        long long f = (v[i] * p) % kMod;
        ans = (ans + f) % kMod;
      } else {
        long long ep = (p + kMod - last_p) % kMod; // effective prob
        long long f = (v[i] * ep) % kMod;
        ans = (ans + f) % kMod;
      }
    }
  }

  long long inv_den = InvMod(Pow(6, n));
  ans = (ans * inv_den) % kMod;
  cout << ans << "\n";

  return 0;
}