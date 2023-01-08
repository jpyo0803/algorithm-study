// 8진수 2진수
// https://www.acmicpc.net/problem/1212

#include <stdio.h>
#include <string.h>

#include <vector>

using namespace std;

char input[333340];

int main() {
  scanf("%s", input);

  if (input[0] == '0') {
    printf("0\n");
    return 0;
  }

  int len = strlen(input);
  for (int i = 0; i < len; i++) {
    if (i > 0 && input[i] < '2')
      printf("00");
    else if (i > 0 && input[i] < '4')
      printf("0");
    if (input[i] == '0')
      printf("0");
    else if (input[i] == '1')
      printf("1");
    else if (input[i] == '2')
      printf("10");
    else if (input[i] == '3')
      printf("11");
    else if (input[i] == '4')
      printf("100");
    else if (input[i] == '5')
      printf("101");
    else if (input[i] == '6')
      printf("110");
    else if (input[i] == '7')
      printf("111");
  }

  return 0;
}
