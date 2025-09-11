// FEB (Bronze)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

#define ll long long

using namespace std;
/*
FFF
홀수 최대: F - 1
홀수 최소: 0

FFFF
짝수 최대: F - 1
짝수 최소: 0

BFFFB:
홀수 양쪽같음 최대: +2
홀수 양쪽같은 최소: +0 

BFFFE
홀수 양쪽다름 최대: +1
홀수 양쪽다름 최소: +1

BFFFFB:
짝수 양쪽 같음 최대: +2
짝수 양쪽 같음 최소: +1

BFFFFE
짝수 양쪽 다름 최대: +1
짝수 양쪽 다름 최소: +0

BFFF: 
홀수 한쪽 최대: +1
홀수 한쪽 최소: +0

BFFFF:
짝수 한쪽 최대: +1
짝수 한쪽 최소: +0
*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  s.push_back('X');

  int offset = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == 'F') continue;
    if (s[i] == s[i + 1]) offset++;
  }
 
  int f = 0;

  int offset2 = 0;
  int lo = 0, hi = 0;

  bool allf = false;
  for (int i = 0; i <= n; ++i) {
    if (s[i] == 'F') {
      f++;
    } else {
      if (f > 0) {
        char a = i - f - 1 >= 0 ? s[i - f - 1] : 'X';
        char b = s[i];
        bool is_odd = f % 2;
        if (a == 'X' && b == 'X') { // both open
          lo = 0, hi = f - 1;
          allf = true;
        } else if (a != 'X' && b != 'X') { // both closed
          if (is_odd) {
            if (a == b) {
              hi += f + 1;
            } else {
              hi += f;
              lo++;
            }
          } else {
            if (a == b) {
              hi += f + 1;
              lo++;
            } else {
              hi += f;
            }
          }
        } else { // one-sided
          offset2 += f;
        }
      }
      f = 0;
    }
  }

  if (allf) {
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
      cout << i << "\n";
    }
    return 0;
  }

  if (offset2 == 0) {
    cout << (hi / 2 - lo / 2) + 1 << "\n";
    for (int i = lo; i <= hi; i += 2) {
      cout << i + offset << "\n";
    }
  } else {
    cout << (hi - lo + 1 + offset2) << "\n";
    for (int i = lo; i <= hi + offset2; ++i) {
      cout << i + offset << "\n";
    }
  }

  return 0;
}