// Mountain View (Silver)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> v(n);

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    // R = x + y, L = x - y
    v[i].first = x - y;
    v[i].second = x + y;
  }

  sort(v.begin(), v.end(), [](pair<int, int> x, pair<int, int> y) {
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
  });

  int ans = 0;
  int last = -1;
  for (auto e : v) {
    if (e.second > last) {
      ans++;
      last = e.second;
    }
  }
  cout << ans << "\n";

  return 0;
}