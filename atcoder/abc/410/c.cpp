// C - Rotatable Array (ABC)
// https://atcoder.jp/contests/abc410/tasks/abc410_c

#include <bits/stdc++.h>

using namespace std;

int n, q, cmd, p, x, k;
int arr[1000005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;

  int h = 0, t = n - 1;
  for (int i = 0; i < n; ++i) arr[i] = i + 1;

  while (q--) {
    cin >> cmd;
    if (cmd == 1) {
      cin >> p >> x;
      arr[(h + p - 1) % n] = x;
    } else if (cmd == 2) {
      cin >> p;
      cout << arr[(h + p - 1) % n] << "\n";
    } else {
      cin >> k;
      k %= n;
      h = (h + k) % n;
      t = (t + k) % n;
    }
  }

  return 0;
}