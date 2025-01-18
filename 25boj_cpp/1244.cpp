// 스위치 켜고 끄
// https://www.acmicpc.net/problem/1244

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<int> sw(n);
  for (int i = 0; i < n; ++i) {
    cin >> sw[i];
  }

  int k;
  cin >> k;

  while (k--) {
    int a, b;
    cin >> a >> b;

    // b is switch position, one-indexed
    if (a == 1) {
      // male student
      for (int i = b - 1; i < n; i += b) {
        sw[i] = 1 - sw[i]; // toggle
      }
    } else {
      b--; // 0-indexed
      int dist = 1;
      while (b - dist >= 0 && b + dist < n) {
        if (sw[b - dist] != sw[b + dist]) break;
        dist++;
      }

      for (int i = b - (dist - 1); i < b + dist; ++i) {
        sw[i] = 1 - sw[i];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (i != 0 && i % 20 == 0) cout << "\n";
    cout << sw[i] << " ";
  }
  cout << "\n";

  return 0;
}