//
// FESTIVAL
// Problem: https://www.algospot.com/judge/problem/read/FESTIVAL
//

#include <cstdio>

constexpr int kMaxSize = 1000;
int C, N, L;
int cost[kMaxSize];
double dp[kMaxSize][kMaxSize];

int main() {
  scanf("%d", &C);
  for (int tc = 0; tc < C; tc++) {
    scanf("%d%d", &N, &L);
    for (int i = 0; i < N; i++) {
      scanf("%d", &cost[i]);
      dp[i][i] = cost[i];
    }

    double min = 1e9;
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j < N - i + 1; j++) {
        dp[j][j + i - 1] = dp[j][j + i - 2] + cost[j + i - 1];
        double candidate = dp[j][j + i - 1] / i;
        if (i >= L) {
          min = candidate < min ? candidate : min;
        }
      }
    }

    printf("%.12f\n", min);
  }
  return 0;
}