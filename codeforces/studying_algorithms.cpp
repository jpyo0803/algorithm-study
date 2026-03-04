// Studying Algorithms
// https://codeforces.com/gym/102951/problem/B

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    x -= v[i];
    if (x < 0) break;
    ans++;
  }

  cout << ans << "\n";

  return 0;
}