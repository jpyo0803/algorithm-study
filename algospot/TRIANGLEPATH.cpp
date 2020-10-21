//
// TRIANGLEPATH
// Problem: https://www.algospot.com/judge/problem/read/TRIANGLEPATH
//

#include <cstdio>
#include <cstring>

constexpr int kMax = 101;

using namespace std;

int C, N;
int arr[kMax][kMax];
int cache[kMax][kMax];

int Max(int x, int y) { return x < y ? y : x; }

int memo(int r, int c) {
  if (r == N - 1) return arr[r][c];

  int& ret = cache[r][c];
  if (ret != -1) return ret;

  ret = Max(memo(r + 1, c), memo(r + 1, c + 1)) + arr[r][c];
  return ret;
}

int main() {
  scanf("%d", &C);

  for (int c = 0; c < C; c++) {
    scanf("%d", &N);
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= i; j++) {
        scanf("%d", &arr[i][j]); 
      }
    }

    printf("%d\n", memo(0, 0));
  }

  return 0;
}