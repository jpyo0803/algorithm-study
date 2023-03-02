// Why Did the Cow Cross the Road III (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=713

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

  sort(v.begin(), v.end());

  int t = 0;

  for (int i = 0; i < N; ++i) {
    if (t < v[i].first) {
      t = v[i].first + v[i].second;
    } else {
      t += v[i].second;
    }
  }

  cout << t << "\n";

  return 0;
}