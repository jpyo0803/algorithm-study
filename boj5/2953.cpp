//
// 나는 요리사다
// Link: https://www.acmicpc.net/problem/2953a
//

#include <cstdio>

int main() {
  int max_val = 0;
  int nth = 1;
  for (int i = 0; i < 5; i++) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
      int x;
      scanf("%d", &x);
      sum += x;
    }
    if (max_val < sum) {
      max_val = sum;
      nth = i + 1;
    }
  }
  printf("%d %d\n", nth, max_val);
  return 0;
}
