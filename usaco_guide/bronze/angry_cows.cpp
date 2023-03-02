// Angry Cows
// http://www.usaco.org/index.php?page=viewproblem2&cpid=592

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

  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int t = 1;

    int pl, pr;
    pl = pr = i;

    int cand = 1;

    bool ldone = false, rdone = false;
    while (true) {
      bool lupdated = false, rupdated = false;

      int l = pl;
      while (!ldone && l - 1 >= 0 && v[pl] - t <= v[l - 1]) {
        ++cand;
        --l;
        lupdated = true;
      }
      pl = l;
      int r = pr;
      while (!rdone && r + 1 < N && v[r + 1] <= v[pr] + t) {
        ++cand;
        ++r;
        rupdated = true;
      }
      pr = r;
      ++t;

      if (!lupdated) ldone = true;
      if (!rupdated) rdone = true;
      if (!lupdated && !rupdated) break;
    }
    ans = max(ans, cand);
  }

  cout << ans << "\n";

  return 0;
}