// 진법 변환
// https://www.acmicpc.net/problem/2745

#include <iostream>

using namespace std;

string N;
int B;

int main() {
  cin >> N >> B;

  int ans = 0;
  for (int i = 0; i < N.size(); i++) {
    char digit_ch = N[i];
    int digit;
    if (digit_ch >= '0' && digit_ch <= '9') {
      digit = digit_ch - '0';
    } else {
      digit = 10 + (digit_ch - 'A');
    }
    ans = ans * B + digit;
  }
  printf("%d\n", ans);
  return 0;
}
