//
// Check if palindrome
// Link: https://www.acmicpc.net/source/21248613
//

#include <iostream>

using namespace std;
string input;

int main() {
  cin >> input;
  bool is_palindrome = true;
  for (int i = 0; i < input.length() / 2; i++) {
    if (input[i] != input[input.length() - 1 - i]) {
      is_palindrome = false;
      break;
    }
  }
  if (is_palindrome) cout << 1 << endl;
  else cout << 0 << endl;
  return 0;
}

