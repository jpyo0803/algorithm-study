// Diamond Collector (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=639

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;

  cin >> N >> K;

  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int cnt = 0;
    for (int j = 0; j < N; ++j) {
      int diff = v[j] - v[i];
      if (diff >= 0 && diff <= K) {
        ++cnt;
      }
    }
    ans = max(ans, cnt);
  }

  cout << ans << "\n";

  return 0;
}