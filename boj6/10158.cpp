// 개미
// https://www.acmicpc.net/problem/10158

#include <stdio.h>

int w, h, p, q, t, x, y;

void Solve() {
  int x_q = (p + t) / w;
  int y_q = (q + t) / h;
  if (x_q % 2)
    x = w - ((p + t) % w);
  else
    x = (p + t) % w;
  if (y_q % 2)
    y = h - ((q + t) % h);
  else
    y = (q + t) % h;
}

int main() {
  scanf("%d%d%d%d%d", &w, &h, &p, &q, &t);
  Solve();
  printf("%d %d\n", x, y);
  return 0;
}
