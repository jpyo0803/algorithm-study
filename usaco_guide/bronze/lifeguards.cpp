// Lifeguards
// http://www.usaco.org/index.php?page=viewproblem2&cpid=784

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<pair<int, int>> v(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end());  // sort it by earlier starting time

  int ans = 0;
  for (int i = 0; i < N; ++i) {  // 'i' to exclude
    int sum = 0;

    int last_ended = -1;
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      if (last_ended > v[j].first) {
        if (last_ended < v[j].second) {
          sum += v[j].second - last_ended;
          last_ended = v[j].second;
        }
      } else {
        sum += v[j].second - v[j].first;
        last_ended = v[j].second;
      }
    }

    ans = max(ans, sum);
  }

  cout << ans << "\n";

  return 0;
}