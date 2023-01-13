// Circular Barn
// http://www.usaco.org/index.php?page=viewproblem2&cpid=616

#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  vector<int> r(N);
  for (int i = 0; i < N; ++i) {
    cin >> r[i];
  }

  int ans = 1e9;
  for (int start = 0; start < N; ++start) {
    int cand = 0;
    for (int moves = 1; moves < N; ++moves) {
        cand += r[(start + moves) % N] * moves;
    }
    ans = min(ans, cand);
  }

  cout << ans << "\n";

  return 0;
}