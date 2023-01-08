//
// Write number continuously 1
// Problem: https://www.acmicpc.net/problem/1748
//

#include <iostream>

using namespace std;
string N;
int main() {
  cin >> N;

  int sum{0};
  int factor{1}, digit{1};
  for (int i = 1; i < N.length(); i++) {
    sum += factor * 9 * digit;
    factor *= 10;
    digit += 1;
  }
  sum += (atoi(N.c_str()) - factor + 1) * digit;
  cout << sum;
  return 0;
}
