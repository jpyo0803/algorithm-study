//
// 구간합 구하기5
// Link: https://www.acmicpc.net/problem/11660
//

#include <cstdio>
#include <cstring>

constexpr int kMax = 1024;

int N, M;
int A[kMax + 1][kMax + 1];
int cache[kMax + 1][kMax + 1];

int GetAnswer(int x1, int y1, int x2, int y2) {
  return cache[x2][y2] - cache[x1][y2] - cache[x2][y1] + cache[x1][y1];
}

int MemoMethod(int r, int c) {
  if (r == 0 || c == 0) return 0;
  if (r == 1 && c == 1) return A[1][1];
  int& ret = cache[r][c];
  if (ret != -1) return ret;

  return ret = MemoMethod(r - 1, c) + MemoMethod(r, c - 1) -
               MemoMethod(r - 1, c - 1) + A[r][c];
}

int main() {
  memset(cache, -1, sizeof(cache));

  scanf("%d%d", &N, &M);
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      scanf("%d", &A[r][c]);
    }
  }

  int x1, y1, x2, y2;
  for (int m = 0; m < M; m++) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1 -= 1;
    y1 -= 1;
    printf("%d\n", MemoMethod(x2, y2) - MemoMethod(x2, y1) -
                       MemoMethod(x1, y2) + MemoMethod(x1, y1));
  }

  return 0;
}