// Carbon Dating
// https://www.acmicpc.net/problem/6323

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int seq = 1;
  while (true) {
    int w, d;
    cin >> w >> d;
    if (w == 0 && d == 0) break;
    if (seq > 1) {
      printf("\n");
    }

    double x = 5730 * log((double)d / 810 / w) / log(0.5);
    if (x < 10000) {
      x = round(x / 100) * 100;
    } else {
      x = round(x / 1000) * 1000;
    }

    printf("Sample #%d\n", seq++);
    printf("The approximate age is %d years.\n", (int)x);
  }

  return 0;
}