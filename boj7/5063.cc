// TGN
// https://www.acmicpc.net/problem/5063

#include <stdio.h>

const char* yes = "advertise";
const char* no = "do not advertise";
const char* dont_care = "does not matter";

int N, r, e, c;

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; n++) {
    scanf("%d%d%d", &r, &e, &c);
    if (r > e - c)
      printf("%s\n", no);
    else if (r < e - c)
      printf("%s\n", yes);
    else
      printf("%s\n", dont_care);
  }
  return 0;
}
