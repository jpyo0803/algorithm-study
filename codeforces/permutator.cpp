// Permutator
// https://codeforces.com/gym/104520/problem/H

#include <bits/stdc++.h>

using namespace std;

int n;

long long F(int i) { return ((long long)i + 1) * (n - i); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<long long> a(n), b(n);
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a[i] = F(i) * x;
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] * b[n - i - 1];
  }

  cout << ans << "\n";

  return 0;
}