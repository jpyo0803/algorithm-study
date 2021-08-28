//
// Change
// Problem: https://www.acmicpc.net/problem/5585
//

#include <cstdio>

int p;
int coin_type[6] = {500, 100, 50, 10, 5, 1};

int main() {
  scanf("%d", &p);

  int change_left = 1000 - p;
  int num_coins = 0;
  for (int i = 0; i < 6; i++) {
    if (change_left >= coin_type[i]) {
      num_coins += change_left / coin_type[i];
      change_left %= coin_type[i];
    }
  }
  printf("%d", num_coins);
}
