//
// PI
// Problem: https://algospot.com/judge/problem/read/PI
//

#include <cstdio>
#include <cstring>
#include <cmath>

constexpr int INF = 987654321;

using namespace std;

int Min(int x, int y) { return x < y ? x : y; }

int C;
int length;
char number[10001];
int cache[10001];

bool IsSame(int x, int dx) {
  for (int i = x + 1; i < x + dx; i++) {
    if (number[i] != number[x]) return false;
  }
  return true;
}

bool IsDifferByOne(int x, int dx) {
  bool first = true;
  int diff;
  for (int i = x; i < x + dx - 1; i++) {
    if (first) {
      first = false;
      diff = number[i + 1] - number[i];
      if (abs(diff) != 1) return false;
    } else {
      if (number[i + 1] - number[i] != diff) return false;
    }
  }
  return true;
}

bool IsAlternating(int x, int dx) {
  for (int i = x; i < x + dx; i++) {
    if (i + 2 < x + dx) {
      if (number[i] != number[i + 2]) return false;
    }
  }
  return true;
}

bool IsArithmeticProgression(int x, int dx) {
  bool first = true;
  int diff;
  for (int i = x; i < x + dx - 1; i++) {
    if (first) {
      first = false;
      diff = number[i + 1] - number[i];
    } else {
      if (number[i + 1] - number[i] != diff) return false;
    }
  }
  return true;
}

int PI(int x) {
  if (x + 3 > length) return INF;
  int& ret = cache[x];
  if (ret != -1) return ret;

  ret = INF;
  for (int i = 3; i <= 5; i++) {
    int difficulty = 10;
    if (IsSame(x, i)) difficulty = 1;
    else if (IsDifferByOne(x, i)) difficulty = 2;
    else if (IsAlternating(x, i)) difficulty = 4;
    else if (IsArithmeticProgression(x, i)) difficulty = 5;
    if (x + i == length) ret = Min(ret, difficulty);
    else ret = Min(ret, PI(x + i) + difficulty);
  }
  return ret;
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    scanf("%s", number);
    length = strlen(number);
    memset(cache, -1, sizeof(cache));

    printf("%d\n", PI(0));
  }
  return 0;
}