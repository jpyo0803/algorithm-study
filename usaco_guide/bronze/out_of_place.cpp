// Out of Place
// http://www.usaco.org/index.php?page=viewproblem2&cpid=785

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  auto sarr = arr;
  sort(sarr.begin(), sarr.end());

  int ans = -1;
  for (int i = 0; i < N; ++i) {
    if (arr[i] != sarr[i]) ans++;
  }

  cout << max(0, ans) << "\n";

  return 0;
}