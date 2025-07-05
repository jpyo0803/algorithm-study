// Even More Odd Photos (Bronze)
// https://www.acmicpc.net/problem/20974

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  int even = 0, odd = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x % 2)
      odd++;
    else
      even++;
  }

  while (!(even == odd || even == odd + 1)) {
    if (even < odd) {
      odd -= 2;
      even++;
    } else if (even > odd + 1) {
      even--;
    }
  }

  cout << even + odd << "\n";

  return 0;
}