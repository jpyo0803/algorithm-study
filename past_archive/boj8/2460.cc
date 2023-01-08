// 지능형 기차 2
// https://www.acmicpc.net/problem/2460

#include <stdio.h>

int main() {
  int max_num = 0;
  int net = 0;
  int out, in;
  for (int i = 0; i < 10; i++) {
    scanf("%d%d", &out, &in);
    net = net - out + in;
    if (net > max_num) max_num = net;
  }
  printf("%d\n", max_num);
  return 0;
}
