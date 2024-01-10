// Maximum Subarray
// https://www.acmicpc.net/problem/10211

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    vector<int> ps(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      int a;
      cin >> a;
      ps[i] = a + ps[i - 1];
    }

    int ans = -1e9;
    for (int i = 1; i <= N; ++i) {
      for (int j = i; j <= N; ++j) {
        ans = max(ans, ps[j] - ps[i - 1]);
      }
    }
    cout << ans << "\n";
  }

  return 0;
}