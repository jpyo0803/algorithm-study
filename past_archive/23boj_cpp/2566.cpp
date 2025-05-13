// 최댓값
// https://www.acmicpc.net/problem/2566

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int maxx = -1;
  int r, c;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      int a;
      cin >> a;
      if (a > maxx) {
        maxx = a;
        r = i + 1;
        c = j + 1;
      }
    }
  }
  cout << maxx << "\n";
  cout << r << " " << c << "\n";

  return 0;
}