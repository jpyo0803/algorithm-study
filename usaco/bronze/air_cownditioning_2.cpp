// Air Cownditioning 2 (Bronze)
// https://www.acmicpc.net/problem/27562

#include <bits/stdc++.h>

using namespace std;

int n, m;

tuple<int, int, int> cows[22];
tuple<int, int, int, int> acs[12];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> get<0>(cows[i]) >> get<1>(cows[i]) >> get<2>(cows[i]);
  }

  for (int i = 0; i < m; ++i) {
    cin >> get<0>(acs[i]) >> get<1>(acs[i]) >> get<2>(acs[i]) >> get<3>(acs[i]);
  }

  int ans = 1e9;
  for (int i = 0; i < (1 << m); ++i) {
    bool ok = true;
    for (int pos = 1; pos <= 100; ++pos) {
      int cool = 0;
      for (int j = 0; j < m; ++j) {
        if ((i >> j) & 0b1) {
          int a, b, p, c;
          tie(a, b, p, c) = acs[j];
          if (a <= pos && pos <= b) {
            cool += p;
          }
        }
      }

      int require = 0;
      for (int j = 0; j < n; ++j) {
        int s, t, c;
        tie(s, t, c) = cows[j];
        if (s <= pos && pos <= t) {
          require = c;
        }
      }
      if (cool < require) ok = false;
    }
    if (ok) {
      int cand = 0;
      for (int j = 0; j < m; ++j) {
        if ((i >> j) & 0b1) {
          cand += get<3>(acs[j]);
        }
      } 
      ans = min(ans, cand);
    }
  }

  cout << ans << "\n";

  return 0;
}