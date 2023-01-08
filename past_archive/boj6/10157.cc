//
// 자리배정
// Link: https://www.acmicpc.net/problem/10157
//

#include <stdio.h>
int C, R, K, rr = -1, cc = -1;
void FillOuter(int sr, int sc, int dr, int dc, int k) {
  int nk;
  if (dr == 1 && dc == 1)
    nk = k;
  else
    nk = k + (2 * (dr + dc)) - 5;
  if (K >= k && K <= nk) {
    int i = sr, j = sc;
    int bk = k, ak;
    ak = bk + (dr - 1);
    i += (dr - 1);
    if (K >= bk && K <= ak) {
      rr = i - (ak - K);
      cc = j;
      return;
    }
    bk = ak;
    ak = bk + (dc - 1);
    j += (dc - 1);
    if (K >= bk && K <= ak) {
      rr = i;
      cc = j - (ak - K);
      return;
    }
    bk = ak;
    ak = bk + (dr - 1);
    i -= (dr - 1);
    if (K >= bk && K <= ak) {
      rr = i + (ak - K);
      cc = j;
      return;
    }
    bk = ak;
    ak = bk + (dc - 2);
    j -= (dc - 2);
    if (K >= bk && K <= ak) {
      rr = i;
      cc = j + (ak - K);
      return;
    }
  }
  if (nk + 1 <= C * R) FillOuter(sr + 1, sc + 1, dr - 2, dc - 2, nk + 1);
}
int main() {
  scanf("%d%d%d", &C, &R, &K);
  FillOuter(1, 1, R, C, 1);
  if (rr == -1)
    printf("0\n");
  else
    printf("%d %d\n", cc, rr);
  return 0;
}
