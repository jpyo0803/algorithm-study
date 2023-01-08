//
// Going down
// Problem: https://www.acmicpc.net/problem/2096
// comment: Memoization method will not pass boj due to max memory limit (~4MB)
//

#include <cstdio>

#define MODE 0  // 0 = Memoization, 1 = Tabulation

int max(int x, int y) { return (x < y) ? y : x; }
int min(int x, int y) { return (x < y) ? x : y; }

int N;
#if (MODE == 0)
const int MAX_SIZE{100000};
int nums[MAX_SIZE + 1][3];
int dp_max[MAX_SIZE + 1][3];
int dp_min[MAX_SIZE + 1][3];
#else
int num1, num2, num3;
int dp_max[2][3];
int dp_min[2][3];
#endif

#if (MODE == 0)
bool filled[MAX_SIZE + 1][3];
void memo_method(int i, int j) {
  if (i == 0) return;
  if (filled[i][j]) return;

  for (int k = 0; k < 3; k++) {
    memo_method(i - 1, k);
  }
  if (j == 0) {
    dp_max[i][0] = max(dp_max[i - 1][0], dp_max[i - 1][1]) + nums[i][0];
    dp_min[i][0] = min(dp_min[i - 1][0], dp_max[i - 1][1]) + nums[i][0];
  } else if (j == 1) {
    dp_max[i][1] =
        max(max(dp_max[i - 1][0], dp_max[i - 1][1]), dp_max[i - 1][2]) +
        nums[i][1];
    dp_min[i][1] =
        min(min(dp_min[i - 1][0], dp_min[i - 1][1]), dp_min[i - 1][2]) +
        nums[i][1];
  } else {
    dp_max[i][2] = max(dp_max[i - 1][1], dp_max[i - 1][2]) + nums[i][2];
    dp_min[i][2] = min(dp_min[i - 1][1], dp_min[i - 1][2]) + nums[i][2];
  }
  filled[i][j] = true;
  return;
}

#else
void tabulate_method(int n) {
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &num1, &num2, &num3);
    int curr = i % 2;
    dp_max[curr][0] = max(dp_max[!curr][0], dp_max[!curr][1]) + num1;
    dp_max[curr][1] =
        max(max(dp_max[!curr][0], dp_max[!curr][1]), dp_max[!curr][2]) + num2;
    dp_max[curr][2] = max(dp_max[!curr][1], dp_max[!curr][2]) + num3;

    dp_min[curr][0] = min(dp_min[!curr][0], dp_min[!curr][1]) + num1;
    dp_min[curr][1] =
        min(min(dp_min[!curr][0], dp_min[!curr][1]), dp_min[!curr][2]) + num2;
    dp_min[curr][2] = min(dp_min[!curr][1], dp_min[!curr][2]) + num3;
  }
}
#endif
int main() {
  scanf("%d", &N);
#if (MODE == 0)
  printf("Memoization\n");
  for (int i = 1; i <= N; i++) {
    scanf("%d%d%d", &nums[i][0], &nums[i][1], &nums[i][2]);
  }
  for (int i = 0; i < 3; i++) {
    memo_method(N, i);
  }
  printf("%d %d", max(max(dp_max[N][0], dp_max[N][1]), dp_max[N][2]),
         min(min(dp_min[N][0], dp_min[N][1]), dp_min[N][2]));
#else
  printf("Tabulation\n");
  tabulate_method(N);
  printf("%d %d",
         max(max(dp_max[N % 2][0], dp_max[N % 2][1]), dp_max[N % 2][2]),
         min(min(dp_min[N % 2][0], dp_min[N % 2][1]), dp_min[N % 2][2]));
#endif
  return 0;
}