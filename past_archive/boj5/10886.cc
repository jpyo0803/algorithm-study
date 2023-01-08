//
// 0 = not cute / 1 = cute
// Link: https://www.acmicpc.net/problem/10886
//

#include <cstdio>

int N;

int main() {
  scanf("%d", &N);
  int c = 0;
  for (int n = 0; n < N; n++) {
    int e;
    scanf("%d", &e);
    c += e;
  }
  if (c > N / 2)
    printf("Junhee is cute!\n");
  else
    printf("Junhee is not cute!\n");
  return 0;
}
