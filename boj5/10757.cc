//
// 큰 수 A+B
// Link: https://www.acmicpc.net/problem/10757
//

#include <iostream>
#include <string>

using namespace std;

string a, b;

int main() {
  cin >> a >> b;

  int i = a.length() - 1;
  int j = b.length() - 1;

  string answer = "";
  int carry = 0;
  while (i > -1 || j > -1) {
    int x = 0;
    int y = 0;
    if (i > -1) x = a[i--] - '0';
    if (j > -1) y = b[j--] - '0';
    int z = x + y + carry;
    if (z > 9) {
      carry = 1;
      z -= 10;
    } else
      carry = 0;
    answer.insert(0, 1, z + '0');
  }
  if (carry == 1) answer.insert(0, 1, carry + '0');
  cout << answer << endl;
  return 0;
}
