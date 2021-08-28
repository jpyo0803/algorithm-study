//
// 캠핑
// Link: https://www.acmicpc.net/problem/4796
//

#include <stdio.h>

int Min(int x, int y) { return x < y ? x : y; }

int main() {
  int L, P, V;
  scanf("%d%d%d", &L, &P, &V);
  int case_count = 1;
  while (L + P + V != 0) {
    int ans = (V / P) * L + Min(V % P, L);

    printf("Case %d: %d\n", case_count++, ans);
    scanf("%d%d%d", &L, &P, &V);
  }
  return 0;
}
