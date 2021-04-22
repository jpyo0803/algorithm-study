// 두부 모판 자르기
// https://www.acmicpc.net/problem/10937

#include <stdio.h>
#include <string.h>

int Max(int x, int y) { return x < y ? y : x; }

int N;
char map[11][11];
int cache[11][11][1 << 12];
int price[4][4] = {
    {100, 70, 40, 0},
    {70, 50, 30, 0},
    {40, 30, 20, 0},
    {0, 0, 0, 0},
};

int GetPrice(char r, char c) { return price[r - 'A'][c - 'A']; }

bool IsBitSet(int bit, int n) { return (bit >> n) & 1; }

int SetBit(int bit, int n) { return bit | (1 << n); }

int TrimNBit(int bit, int n) { return bit % (1 << (n + 1)); }

int Solve(int r, int c, int bit) {
  if (r == N) return 0;
  if (c == N) return Solve(r + 1, 0, bit);

  int &ret = cache[r][c][bit];
  if (ret != -1) return ret;

  if (!IsBitSet(bit, N)) {
    if (c + 1 < N && !IsBitSet(bit, N - 1)) {
      ret = Max(ret, Solve(r, c + 2, TrimNBit(SetBit(bit, N - 1) << 2, N)) +
                         GetPrice(map[r][c], map[r][c + 1]));
    }
    if (r + 1 < N && !IsBitSet(bit, 0)) {
      ret = Max(ret, Solve(r, c + 1, TrimNBit(SetBit(bit, 0) << 1, N)) +
                         GetPrice(map[r][c], map[r + 1][c]));
    }
    ret = Max(ret, Solve(r, c + 1, TrimNBit(bit << 1, N)));
  } else {
    ret = Max(ret, Solve(r, c + 1, TrimNBit(bit << 1, N)));
  }
  return ret;
}

int main() {
  memset(cache, -1, sizeof(cache));
  scanf("%d", &N);
  char input[12];
  for (int r = 0; r < N; r++) {
    scanf("%s", input);
    for (int c = 0; c < N; c++) {
      map[r][c] = input[c] == 'F' ? 'D' : input[c];
    }
  }
  printf("%d\n", Solve(0, 0, 0));

  return 0;
}
