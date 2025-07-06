// Out of Place (Bronze)
// https://www.acmicpc.net/problem/15594

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

  auto v2 = v;
  sort(v2.begin(), v2.end());

  int s = -1, t = -1;
  for (int i = 0; i < n; ++i) {
    if (v[i] != v2[i]) {
      if (s == -1) s = i;
      t = i;
    }
  }

  int ans = 0;

  if (s != -1) {
    int c = v[s];
    for (int i = s; i <= t; ++i) {
      if (v[i] != c) {
        c = v[i];
        ans++;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}