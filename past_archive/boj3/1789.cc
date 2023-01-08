//
// Sum of Numbers
// Problem: https://www.acmicpc.net/problem/1789
//

#include <iostream>
using namespace std;
uint64_t S;
int main() {
  cin >> S;
  uint64_t N = 1;
  while (N * (N + 1) / 2 <= S) N++;
  cout << N - 1;
  return 0;
}