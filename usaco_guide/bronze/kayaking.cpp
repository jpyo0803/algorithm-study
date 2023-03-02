// Kayaking
// https://codeforces.com/contest/863/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> w(2 * N);
  for (int i = 0; i < 2 * N; ++i) {
    cin >> w[i];
  }

  sort(w.begin(), w.end());

  int ans = 1e9;

  for (int i = 0; i < 2 * N - 1; ++i) {
    for (int j = i + 1; j < 2 * N; ++j) {
      // two are chosen
      int chosen[2];
      int k = 0;

      int cnt = 0;
      int cand = 0;

      while (k < 2 * N) {
        if (k == i || k == j) {
          k++;
          continue;  // skip
        }
        chosen[cnt] = w[k];
        ++cnt;
        if (cnt == 2) {
          cand += chosen[1] - chosen[0];
          chosen[0] = chosen[1] = cnt = 0;
        }
        k++;
      }

      ans = min(ans, cand);
    }
  }

  cout << ans << "\n";

  return 0;
}
