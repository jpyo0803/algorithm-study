// F - Lost and Pound (ABC)
// https://atcoder.jp/contests/abc404/tasks/abc404_f

#include <bits/stdc++.h>

using namespace std;

int N, T, M, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> T >> M >> K;

  vector<vector<double>> dp(T + 1, vector<double>(M + K + 1, 0));

  // T라운드 끝나고 k이상 승리버튼 누르면 승리 확률은 1
  for (int i = 0; i < M + K + 1; ++i) dp[T][i] = i >= K ? 1.0 : 0.0;

  for (int t = T - 1; t >= 0; --t) {
    for (int k = K; k <= M + K; ++k) dp[t][k] = 1.0;

    for (int k = 0; k < K; ++k) { // K 이상은 이미 승리이므로 계산할 필요가 없음
      // dp[t][k] 

      // n개의 버튼 중에서 M개의 선택을 어떻게 분배했을때 승리 확률을 최대로 할 수 있을까?
      vector<vector<double>> dp2(M + 1, vector<double>(M + 1, 0));

      for (int i = 1; i <= M; ++i) {
        dp2[1][i] = dp[t + 1][k + i];
      }

      for (int i = 2; i <= M; ++i) {
        for (int j = i; j <= M; ++j) {
          double ma = 0.0;
          for (int l = 1; l <= 1 - i + j; ++l) {
            ma = max(ma, dp2[i - 1][j - l] + dp[t + 1][k + l]);
          }
          dp2[i][j] = ma;
        }
      }

      double best = 0.0;
      for (int i = 1; i <= min(N, M); ++i) {
        best = max(best, dp2[i][M] + (N - i) * dp[t + 1][k]);
      }
      dp[t][k] = best / N;
    }
  }

  cout << fixed << setprecision(10) << dp[0][0] << "\n";

  return 0;
}