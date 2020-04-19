//
// Coin 2
// Problem: https://www.acmicpc.net/problem/2294
//

#include <iostream>

#define MODE 2 // 0 = memoization, 1 = tabulation, 2 = tabulation with 1-D array

using namespace std;

const int MAX_COIN{100};
const int MAX_VALUE{10000};
const int INF{100000000};

int N, K;
int coins[MAX_COIN + 1];
int dp[MAX_COIN + 1][MAX_VALUE + 1];

#if (MODE == 0)
int memo_method(int i, int k) {
    if (k < 0) return INF;
    if (i == 0) {
        if (k == 0) return 0;
        else return INF;
    }

    if (dp[i][k]) return dp[i][k];

    dp[i][k] = min(memo_method(i - 1, k), memo_method(i, k - coins[i]) + 1);
    return dp[i][k];
}
#elseif (MODE == 1)
int tabulate_method(int N, int K) {
    for (int i = 1; i <= K; i++) {
        dp[0][i] = INF;
    }
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int k = 0; k <= K; k++) {
            int dp_i_kc = INF;
            if (k - coins[i] >= 0) {
                dp_i_kc = dp[i][k - coins[i]];
            }
            dp[i][k] = min(dp[i - 1][k], dp_i_kc + 1);
        }
    }
    return dp[N][K];
}
#else
int dp_1d[MAX_VALUE + 1];
int tabulate_method2(int N, int K) {
    for (int i = 1; i <= K; i++) {
        dp_1d[i] = INF;
    }

    for (int i = 1; i <= N; i++) {
        for (int k = coins[i]; k <= K; k++) {
            dp_1d[k] = min(dp_1d[k], dp_1d[k - coins[i]] + 1);
        }
    }
    return dp_1d[K];
}
#endif
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> coins[i];
    }

#if (MODE == 0)
    int res = memo_method(N, K);
    if (res >= INF) cout << -1;
    else cout << res;
#elseif (MODE == 1)
    int res = tabulate_method(N, K);
    if (res >= INF) cout << -1;
    else cout << res;
#else
    int res = tabulate_method2(N, K);
    if (res >= INF) cout << -1;
    else cout << res;
#endif
    return 0;
}