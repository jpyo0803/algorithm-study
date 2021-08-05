//
// Allowance Management
// Problem: https://www.acmicpc.net/problem/6236
//

#include <cstdio>

const int MAX{100000};
int N, M;
int amount;

int daily_spend[MAX];

int K = 1000000000;

int NumWithDraw(int max_withdraw) {
  int num_withdraw = 0;
  int money_left = 0;
  for (auto to_spend : daily_spend) {
    if (to_spend > money_left) {
      num_withdraw += 1;
      money_left = max_withdraw;
    }
    money_left -= to_spend;
  }
  return num_withdraw;
}

void BinarySearch(int left, int right) {
  if (left > right) return;

  int mid = (left + right) / 2;

  int num_withdraw = NumWithDraw(mid);
  if (num_withdraw <= M) {
    K = mid < K ? mid : K;
    BinarySearch(left, mid - 1);
  } else {
    BinarySearch(mid + 1, right);
  }
}

int main() {
  scanf("%d%d", &N, &M);
  int lower_bound = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &daily_spend[i]);
    lower_bound = lower_bound < daily_spend[i] ? daily_spend[i] : lower_bound;
  }

  BinarySearch(lower_bound, 1000000000);
  printf("%d", K);
  return 0;
}

