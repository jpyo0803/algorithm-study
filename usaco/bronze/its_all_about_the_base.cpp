// It's All About the Base (Bronze)
// https://www.acmicpc.net/problem/10677

#include <bits/stdc++.h>

using namespace std;

int GetN(int x, int a) {
  int f = 1;
  int ret = 0;
  for (int i = 0; i < 3; ++i) {
    int d = a % 10;
    a /= 10;
    ret += f * d;
    f *= x;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int k;
  cin >> k;

  while (k--) {
    int a, b;
    cin >> a >> b;
   
    int x = 10, y = 10;
    while (true) {
      int n1 = GetN(x, a);
      int n2 = GetN(y, b);
      if (n1 == n2) {
        cout << x << " " << y << "\n";
        break;
      } else if (n1 < n2) {
        x++;
      } else {
        y++;
      }
    }
  }

  return 0;
}