// The Bucket List
// http://www.usaco.org/index.php?page=viewproblem2&cpid=856

#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  // keeps track of # buckets required at a given moment
  vector<int> buckets(1001);

  for (int i = 0; i < N; ++i) {
    int s, t, b;
    cin >> s >> t >> b;
    for (int j = s; j <= t; ++j) {
      buckets[j] += b;
    }
  }

  int ans = 0;
  for (int i = 1; i <= 1000; ++i) {
    ans = max(ans, buckets[i]);
  }

  cout << ans << "\n";

  return 0;
}