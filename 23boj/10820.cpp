// 문자열 분석
// https://www.acmicpc.net/problem/10820

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string line;

  while (getline(cin, line)) {
    int a = 0, b = 0, c = 0, d = 0;
    for (auto ch : line) {
      if (ch == ' ') {
        d++;
      } else if (ch >= 'a' && ch <= 'z') {
        a++;
      } else if (ch >= 'A' && ch <= 'Z') {
        b++;
      } else if (ch >= '0' && ch <= '9') {
        c++;
      }
    }
    cout << a << " " << b << " " << c << " " << d << "\n";
  }

  return 0;
}