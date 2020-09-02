//
// JUMPGAME
// Problem: https://www.algospot.com/judge/problem/read/JUMPGAME
//

#include <cstdio>

constexpr int kMax = 100;

using namespace std;

int C, N;
int map[kMax][kMax];
bool cache[kMax][kMax];

bool InRange(int r, int c) { return r >= 0 && r < N && c >= 0 && c < N; }

void memo_method(int r, int c) {
  if (!InRange(r, c)) return;
  if (cache[r][c]) return;

  cache[r][c] = true;
  memo_method(r + map[r][c], c);
  memo_method(r, c + map[r][c]);
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &map[i][j]);
        cache[i][j] = false;
      }
    }

    memo_method(0, 0);
    printf("%s\n", cache[N - 1][N - 1] ? "YES" : "NO");
  }
  return 0;
}