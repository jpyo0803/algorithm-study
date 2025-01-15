// 삼각형과 세 변
// https://www.acmicpc.net/problem/5073

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b, c;

  while (true) {
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) {
      break;
    }

    int sum = a + b + c;
    int max_val = max(a, max(b, c));
    if (sum - max_val <= max_val) {
      cout << "Invalid\n";
    } else {
      if (a == b && b == c) {
        cout << "Equilateral\n";
      } else if (a == b || b == c || a == c) {
        cout << "Isosceles\n";
      } else {
        cout << "Scalene\n";
      }
    }
  }

  return 0;
}