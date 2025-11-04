// Guess the K-th Zero (Easy version)
// https://codeforces.com/contest/1520/problem/F1

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, t;
  cin >> n >> t;
  while (t--) {
    int k;
    cin >> k;

    int l = 1, r = n;
    while (l <= r) {
      int m = (l + r) / 2;
      cout << "? " << l << " " << m << "\n";
      cout.flush();

      int res;
      cin >> res;
      if (res == -1) exit(0);

      int zero_cnt = m - l + 1 - res;
      if (zero_cnt < k) {
        l = m + 1;
        k -= zero_cnt;
      } else {
        r = m - 1;
      }
    }
    cout << "! " << l << "\n";
  }

  return 0;
}