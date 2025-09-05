// C - ~ (ABC)
// https://atcoder.jp/contests/abc406/tasks/abc406_c

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<char, int>> v;

  int p;
  cin >> p;
  for (int i = 1; i < n; ++i) {
    int c;
    cin >> c;
    if (p < c) {
      if (v.empty() || v.back().first == '>') {
        v.emplace_back('<', 1);
      } else {
        v.back().second++;
      }
    } else {
      if (v.empty() || v.back().first == '<') {
        v.emplace_back('>', 1);
      } else {
        v.back().second++;
      }
    }

    p = c;
  }

  long long ans = 0;
  for (int i = 1; i < v.size() - 1; ++i) {
    if (v[i].first == '>') ans += (long long)v[i - 1].second * v[i + 1].second;
  }
  cout << ans << "\n";

  return 0;
}