//
// LIS
// Problem: https://www.algospot.com/judge/problem/read/LIS
//

#include <cstdio>
#include <cstring>

using namespace std;

constexpr int kMax = 501;

int C, N;

int seq[kMax];
int cache[kMax];

int Max(int x, int y) { return x > y ? x : y; }

int Memo(int x) {
  int& ret = cache[x];
  if (ret != -1) return ret;

  ret = 1;
  for (int i = 0; i < x; i++) {
    if (seq[i] < seq[x]) {
      ret = Max(ret, Memo(i) + 1);
    }
  }
  return ret;
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    scanf("%d", &N);
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; i++) {
      scanf("%d", &seq[i]);
    }

    seq[N] = 100000000;
    printf("%d\n", Memo(N) - 1);
  }
  return 0;
}