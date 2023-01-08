//
// Perfect Square
// Problem: https://www.acmicpc.net/problem/1977
//

#include <cmath>
#include <cstdio>
int M, N;

int main() {
  scanf("%d%d", &M, &N);
  int sidx = ceil(sqrt(M));
  int sum = 0;
  int min;
  bool first{true};
  for (int i = ceil(sqrt(M)); i <= floor(sqrt(N)); i++) {
    sum += i * i;
    if (first) {
      first = false;
      min = i * i;
    }
  }
  if (first)
    printf("-1");
  else
    printf("%d\n%d", sum, min);
  return 0;
}
