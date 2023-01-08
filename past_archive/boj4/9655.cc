//
// Stone Game
// Link: https://www.acmicpc.net/problem/9655
//

#include <cstdio>
int N;

int main() {
  scanf("%d", &N);
  if (N % 2)
    printf("SK\n");
  else
    printf("CY\n");
}