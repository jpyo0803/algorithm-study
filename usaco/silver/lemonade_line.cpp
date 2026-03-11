// Lemonade Line (Silver)
// https://www.acmicpc.net/problem/15761

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (ans <= v[i]) ans++;
  }
  cout << ans << "\n";

  return 0;
}