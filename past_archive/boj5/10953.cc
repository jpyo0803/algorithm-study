//
// A+B - 6
// Link: https://www.acmicpc.net/problem/10953
//

#include <cstdio>

int T;
char input[4];
int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%s", input);
    printf("%d\n", input[0] - '0' + input[2] - '0');
  }
  return 0;
}