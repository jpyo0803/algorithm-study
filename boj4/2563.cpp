//
// Color Paper
// Link: https://www.acmicpc.net/problem/2563
//

#include <cstdio>

using namespace std;
int N, r, c;
bool dohwaji[105][105];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &c, &r);
    for (int i = r; i < r + 10; i++) {
      for (int j = c; j < c + 10; j++) {
        dohwaji[i][j] = true;
      }
    }
  }

  int filled_count = 0;
  for (int i = 0; i < 105; i++) {
    for (int j = 0; j < 105; j++) {
      if (dohwaji[i][j]) filled_count++;
    }
  }
  printf("%d\n", filled_count);

  return 0;
}