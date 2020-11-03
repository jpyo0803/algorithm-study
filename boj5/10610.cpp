//
// 30
// Link: https://www.acmicpc.net/problem/10610
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  string N;
  cin >> N;
  int sum = 0;
  bool exist_zero = false;
  for (char ch_digit : N) {
    int digit = ch_digit - '0';
    sum += digit;
  }

  sort(N.rbegin(), N.rend());
  if ((sum % 3 == 0) && (N[N.length() - 1] == '0')) {
    cout << N << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}