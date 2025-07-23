// A - Zero-Sum Ranges (AGC)
// https://atcoder.jp/contests/agc023/tasks/agc023_a

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  long long sum = 0;

  vector<long long> ps;
  ps.push_back(0);
  ps.reserve(n + 10);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    sum += a;
    ps.push_back(sum);
  }

  sort(ps.begin(), ps.end());

  long long ans = 0;

  long long cnt = 1;
  long long last_val;
  bool first = true;
  for (auto e : ps) {
    if (first) {
      last_val = e;
      first = false;
    } else {
      if (e != last_val) {
        ans += (cnt * (cnt - 1)) / 2;
        last_val = e;
        cnt = 1;
      } else {
        cnt++;
      }
    }
  }

  ans += (cnt * (cnt - 1)) / 2;

  cout << ans << "\n";

  return 0;
}