//
// Date calculation
// Problem: https://www.acmicpc.net/problem/1476
//

#include <iostream>

using namespace std;

int E, S, M, e, s, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> E >> S >> M;
  e = s = m = 1;

  int year = 1;
  while (true) {
    if (e == E && s == S && m == M) break;
    e++;
    s++;
    m++;
    if (e == 16) e = 1;
    if (s == 29) s = 1;
    if (m == 20) m = 1;
    year += 1;
  }
  cout << year;

  return 0;
}
