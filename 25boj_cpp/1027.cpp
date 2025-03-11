// 고층 건물
// https://www.acmicpc.net/problem/1027

#include <bits/stdc++.h>

using namespace std;

int n;

pair<int, int> GetSlope(pair<int, int> p1, pair<int, int> p2) {
  assert(p1.first < p2.first);
  return {p2.first - p1.first, p2.second - p1.second};  // dx, dy
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // O(N^2)
  cin >> n;

  vector<int> vv(n);
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; ++i) cin >> vv[i];

  // count the number can see and be seen on the right side
  for (int i = 0; i < n - 1; ++i) {
    pair<int, int> last_max_slope;
    bool first = true;
    for (int j = i + 1; j < n; ++j) {
      auto slope = GetSlope({i, vv[i]}, {j, vv[j]});

      bool ok = false;
      if (first) {
        first = false;
        last_max_slope = slope;
        ok = true;
      } else {
        if ((long long)last_max_slope.second * slope.first <
            (long long)last_max_slope.first * slope.second) {
          ok = true;
          last_max_slope = slope;
        }
      }

      if (ok) {
        cnt[i]++;
        cnt[j]++;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(cnt[i], ans);
  }

  cout << ans << "\n";

  return 0;
}