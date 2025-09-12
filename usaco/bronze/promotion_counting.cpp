// Promotion Counting (Bronze)
// https://www.acmicpc.net/problem/11976

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int ans[3]{};
  int x = 0;

  pair<int, int> p[4]{};
  for (int i = 0; i < 4; ++i) cin >> p[i].first >> p[i].second;

  for (int i = 3; i >= 0; --i) {
    x += p[i].second - p[i].first;
    ans[i - 1] = x;
  }

  for (int i = 0; i < 3; ++i) cout << ans[i] << "\n";

  return 0;
}