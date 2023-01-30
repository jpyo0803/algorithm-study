// Daisy Chains (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1060

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> f(N);
  for (int i = 0; i < N; ++i) {
    cin >> f[i];
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int sum = 0;
    for (int j = i; j < N; ++j) {
      sum += f[j];  // sum thru [i, j]
      int cnt = j - i + 1;
      bool ok = false;
      for (int k = i; k <= j; ++k) {
        if (sum == f[k] * cnt) {
          ok = true;
          break;
        }
      }
      if (ok) ++ans;
    }
  }
  cout << ans << "\n";

  return 0;
}