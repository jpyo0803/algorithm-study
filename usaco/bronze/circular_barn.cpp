// Circular Barn (Bronze)
// https://www.acmicpc.net/problem/12000

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

  int ans = 1e9;
  for (int i = 0; i < n; ++i) {
    int j = 0;
    int cand = 0;
    while (j < n) {
      cand += v[(i + j) % n] * j;
      j++;
    }
    ans = min(ans, cand);
  }

  cout << ans << "\n";

  return 0;
}