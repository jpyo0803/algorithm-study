// 주유소
// https://www.acmicpc.net/problem/13305

#include <inttypes.h>
#include <stdio.h>

int N;
int dist[100000];

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N - 1; n++) scanf("%d", &dist[n]);
  int64_t cost = 0;
  int64_t min_price = 1000000000001;
  int price;
  for (int n = 0; n < N; n++) {
    scanf("%d", &price);
    min_price = price < min_price ? price : min_price;
    cost += min_price * dist[n];
  }
  printf("%" PRId64 "\n", cost);

  return 0;
}
