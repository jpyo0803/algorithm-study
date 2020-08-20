//
// Suyeol 축소
// Link: https://www.acmicpc.net/problem/2237
//

#include <cstdio>
constexpr int kMax = 100;
constexpr int kMaxVal = 10000;
constexpr int OFFSET = 10000;

using namespace std;
int N, T;
int nums[kMax + 1];
bool dp[kMax + 1][OFFSET + kMaxVal + 1];
bool sign[kMax + 1];  // + = true, - = false

void tabulate_method() {
  dp[1][nums[1] + OFFSET] = dp[2][nums[1] - nums[2] + OFFSET] = true;
  for (int i = 3; i <= N; i++) {
    for (int j = -10000 + OFFSET; j <= 10000 + OFFSET; j++) {  // 0 ~ 20000
      if (dp[i - 1][j]) {
        if (j - nums[i] >= 0) dp[i][j - nums[i]] = true;
        if (j + nums[i] <= 20000) dp[i][j + nums[i]] = true;
      }
    }
  }
}

int main() {
  scanf("%d%d", &N, &T);
  for (int i = 1; i <= N; i++) scanf("%d", &nums[i]);
  tabulate_method();

  int current_value = T + OFFSET;
  for (int i = N; i > 1; i--) {
    sign[i] = dp[i - 1][current_value - nums[i]];
    current_value = sign[i] ? current_value - nums[i] : current_value + nums[i];
  }
  sign[1] = true;

  int curr = 2;
  while (curr <= N) {
    if (!sign[curr]) {
      if (curr + 1 <= N && sign[curr + 1]) {
        int curr2 = curr + 1;
        while (curr2 <= N && sign[curr2]) {
          printf("2\n");
          curr2++;
        }
        curr = curr2;
        printf("1\n");
      } else {
        printf("1\n");
        curr++;
      }
    }
  }

  return 0;
}