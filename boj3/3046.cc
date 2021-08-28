//
// R2
// Problem:https://www.acmicpc.net/problem/3046
//

#include <cstdio>
int R1, S;
int main() {
  scanf("%d%d", &R1, &S);
  printf("%d", (S << 1) - R1);
  return 0;
}