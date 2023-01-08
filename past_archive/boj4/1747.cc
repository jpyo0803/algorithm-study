//
// Prime and Palindrome Number
// Link: https://www.acmicpc.net/problem/1747
//

#include <cmath>
#include <iostream>

using namespace std;

int N;

bool IsPrime(int x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}

bool IsPalindrome(int x) {
  if (x < 2) return false;
  string s = to_string(x);
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - 1 - i]) return false;
  }
  return true;
}

int Solve() {
  int i = N;
  while (true) {
    if (IsPalindrome(i) && IsPrime(i)) return i;
    i++;
  }
  return -1;
}

int main() {
  cin >> N;
  cout << Solve() << endl;
  return 0;
}