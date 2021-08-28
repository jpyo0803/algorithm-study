//
// Curious Minho
// Problem: https://www.acmicpc.net/problem/1507
//

#include <cstdio>
const int MAX{20};
int N;
int dp[MAX][MAX];
bool connected[MAX][MAX];

int Modified_FW() {
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (k != i && k != j) {
          if (dp[i][k] + dp[k][j] == dp[i][j]) {
            connected[i][j] = false;
          } else if (dp[i][k] + dp[k][j] < dp[i][j]) {
            return -1;
          }
        }
      }
    }
  }
  int sum{0};

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (connected[i][j]) {
        sum += dp[i][j];
      }
    }
  }
  return sum;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &dp[i][j]);
      if (dp[i][j] > 0) {
        connected[i][j] = true;
      }
    }
  }
  printf("%d", Modified_FW());
  return 0;
}
