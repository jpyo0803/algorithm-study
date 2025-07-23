// B - Reverse Proxy (ABC)
// https://atcoder.jp/contests/abc410/tasks/abc410_b

#include <bits/stdc++.h>

using namespace std;

int n, q;

int box[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  while (q--) {
    int x;
    cin >> x;
    if (x > 0) {
      box[x]++;
      cout << x << " ";
    } else {
      int min_val = 1e9;
      int min_pos = -1;
      for (int i = 1; i <= n; ++i) {
        if (box[i] < min_val) {
          min_val = box[i];
          min_pos = i;
        }
      }
      box[min_pos]++;
      cout << min_pos << " ";
    }
  }
  cout << "\n";

  return 0;
}