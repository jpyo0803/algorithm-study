//
// JLIS
// Problem: https://www.algospot.com/judge/problem/read/JLIS
//

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <limits>

using namespace std;

constexpr int64_t NINF = numeric_limits<int64_t>::min();

int C, N, M;
int64_t narr[101];
int64_t marr[101];

int cache[101][101];

int64_t Max(int64_t x, int64_t y) { return x > y ? x : y; }

int JLIS(int n, int m) {
  int& ret = cache[n][m];
  if (ret != -1) return ret;

  ret = (narr[n] == marr[m] ? 1 : 2);
  int add = (narr[n] == marr[m] ? 0 : 1);

  int64_t bigger = Max(narr[n], marr[m]);
  for (int nn = n + 1; nn <= N; nn++) {
    if (bigger < narr[nn]) {
      ret = Max(ret, JLIS(nn, m) + add);
    }
  }
  for (int nm = m + 1; nm <= M; nm++) {
    if (bigger < marr[nm]) {
      ret = Max(ret, JLIS(n, nm) + add);
    }
  }
  return ret;
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) scanf("%ld", &narr[i]);
    for (int i = 1; i <= M; i++) scanf("%ld", &marr[i]);

    memset(cache, -1, sizeof(cache));
    narr[0] = marr[0] = NINF;
    printf("%d\n", JLIS(0, 0) - 1);
  }
  return 0;
}