// 전자레인지
// https://www.acmicpc.net/problem/10162

#include <stdio.h>

int T;
int buttons[3] = {300, 60, 10};

int main() {
  scanf("%d", &T);
  if (T % buttons[2] != 0) {
    printf("-1\n");
    return 0;
  }

  for (int i = 0; i < 3; i++) {
    printf("%d ", T / buttons[i]);
    T %= buttons[i];
  }

  return 0;
}
