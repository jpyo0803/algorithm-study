// Cow College (Bronze)
// https://www.acmicpc.net/problem/26975

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());

  long long max_earn = 0;
  int opt_tui;

  for (int i = 0; i < n; ++i) {
    long long cand = (long long)v[i] * (n - i);
    if (cand > max_earn) {
      max_earn = cand;
      opt_tui = v[i];
    }
  }

  cout << max_earn << " " << opt_tui << "\n";

  return 0;
}