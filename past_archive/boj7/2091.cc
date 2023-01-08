// 동전
// https://www.acmicpc.net/problem/2091

#include <stdio.h>

int X;
int num_coins[4];
int num_coins_rem[4];
int price[4] = {1, 5, 10, 25};
int cache[10001];
int ans[4];

void Solve(int money_sum, int coin_sum) {
  if (cache[money_sum] >= coin_sum) return;
  cache[money_sum] = coin_sum;

  if (money_sum == X) {
    for (int i = 0; i < 4; i++) {
      ans[i] = num_coins[i] - num_coins_rem[i];
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (num_coins_rem[i] > 0 && money_sum + price[i] <= X) {
      num_coins_rem[i]--;
      Solve(money_sum + price[i], coin_sum + 1);
      num_coins_rem[i]++;
    }
  }
}

int main() {
  scanf("%d", &X);
  for (int i = 0; i <= X; i++) {
    cache[i] = -1;
  }
  for (int i = 0; i < 4; i++) {
    scanf("%d", &num_coins[i]);
    num_coins_rem[i] = num_coins[i];
  }

  Solve(0, 0);
  for (int i = 0; i < 4; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
