// Sleepy Cow Sorting (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=892

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  int ans = 0;

  for (int i = 0; i < N - 1; ++i) {
    if (v[i] > v[i + 1]) {
      ans = i + 1;
    }
  }

  cout << ans << "\n";

  return 0;
}