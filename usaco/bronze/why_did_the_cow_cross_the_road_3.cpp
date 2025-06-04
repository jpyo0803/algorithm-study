// Why Did the Cow Cross the Road III (Bronze)
// https://www.acmicpc.net/problem/14469

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

  sort(v.begin(), v.end());

  int curr_time = 0;
  for (auto e : v) {
    int start, duration;
    tie(start, duration) = e;

    curr_time = max(curr_time, start) + duration;
  }

  cout << curr_time << "\n";

  return 0;
}