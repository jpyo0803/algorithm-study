// Drought (Bronze)
// https://www.acmicpc.net/problem/24496

#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 0; i < n; ++i) cin >> h[i];
    h[n] = 2e9;

    if (n == 1) {
      cout << "0\n";
    } else if (n == 2) {
      cout << (h[0] == h[1] ? 0 : -1) << "\n";
    } else {
      long long ans = 0;
      bool ok = true;

      for (int i = 1; i < n; ++i) {
        if (h[i] < 0) {
          ok = false;
          break;
        }
        
        int d = h[i] - h[i - 1];
        if (d >= 0) {
          h[i] -= d, h[i + 1] -= d;
          ans += d * 2;
        } else {
          if (i % 2) {
            ok = false;
            break;
          }
          ans -= (long long)d * i;
        }
      }

      if (h[n] != 2e9) ok = false;

      cout << (ok ? ans : -1) << "\n";
    }
  }

  return 0;
}