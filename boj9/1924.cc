// 2007년
// https://www.acmicpc.net/problem/1924

#include <stdio.h>

const char* days_in_week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  int days = y - 1;
  for (int i = 0; i < x - 1; ++i) {
    days += days_in_month[i];
  }

  printf("%s\n", days_in_week[days % 7]);
  return 0;
}