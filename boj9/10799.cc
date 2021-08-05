// 쇠막대기
// https://www.acmicpc.net/problem/10799

#include <stdio.h>
#include <string.h>

char input[100010];

int stack_size = 0;

int main() {
  scanf("%s", input);

  int length = strlen(input);

  int ans = 0;
  int last_open = 0;

  for (int i = 0; i < length; ++i) {
    if (input[i] == '(') {
      last_open = i;
      ++stack_size;
    } else {
      --stack_size;
      if (last_open + 1 == i) {  // laser
        ans += stack_size;
      } else {
        ans += 1;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}