// Palindromes Coloring
// https://codeforces.com/problemset/problem/1624/D

#include <bits/stdc++.h>

using namespace std;

int t;

int Solve(int n, int k, string s) {
  vector<int> cnt(26, 0);
  for (auto ch : s) cnt[ch - 'a']++;
  
  int pair_cnt = 0;
  int odd_cnt = 0;

  for (int i = 0; i < 26; ++i) {
    pair_cnt += cnt[i] & ~1;
    odd_cnt += cnt[i] & 1;
  }
  pair_cnt /= 2;

  int ret = 2 * (pair_cnt / k);
  odd_cnt += 2 * (pair_cnt % k);

  if (odd_cnt >= k) ret++;

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    cout << Solve(n, k, s) << "\n";
  }

  return 0;
}