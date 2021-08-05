// 직사각형 네개의 합집합의 면적 구하기
// https://www.acmicpc.net/problem/2669

#include <stdio.h>

bool map[101][101];
int x1, y1, x2, y2;

int main() {
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    for (int j = y1; j < y2; ++j) {
      for (int k = x1; k < x2; ++k) {
        if (!map[j][k]) {
          ans++;
          map[j][k] = true;
        }
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}