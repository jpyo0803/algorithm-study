// Cowntact Tracing (Bronze)
// https://www.acmicpc.net/problem/18882

#include <bits/stdc++.h>

using namespace std;

int n, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> t;
  string fs;  // final state
  cin >> fs;

  vector<tuple<int, int, int>> tv(t);
  for (int i = 0; i < t; ++i) {
    cin >> get<0>(tv[i]) >> get<1>(tv[i]) >> get<2>(tv[i]);
  }

  sort(tv.begin(), tv.end());

  int ans = 0;
  int min_k = 1e9;
  int max_k = 0;

  string ss;
  for (int i = 0; i < n; ++i) ss.push_back('0');

  for (int i = 0; i < n; ++i) {
    bool ok = false;
    for (int k = 0; k < t + 5; ++k) {
      string cs = ss;
      cs[i] = '1';

      vector<int> remain_k(n, 0);
      remain_k[i] = k;
      for (auto [t, x, y] : tv) {
        x--, y--;
        if (cs[x] == '0' && cs[y] == '0') {
          continue;  // neither can spread
        } else if (cs[x] == '1' && cs[y] == '1') {
          if (remain_k[x] > 0) remain_k[x]--;
          if (remain_k[y] > 0) remain_k[y]--;
          // use their spread chance, but no additional infection
        } else if (cs[x] == '1') {
          // y is not infected yet
          if (remain_k[x] > 0) {
            cs[y] = '1';
            remain_k[x]--;
            remain_k[y] = k;
          }
        } else if (cs[y] == '1') {
          if (remain_k[y] > 0) {
            cs[x] = '1';
            remain_k[y]--;
            remain_k[x] = k;
          }
        }
      }

      if (cs == fs) {
        ok = true;
        min_k = min(min_k, k);
        max_k = max(max_k, k);
      }
    }
    if (ok) ans++;
  }

  cout << ans << " " << min_k << " ";
  if (max_k > t + 2) {
    cout << "Infinity\n";
  } else {
    cout << max_k << "\n";
  }

  return 0;
}