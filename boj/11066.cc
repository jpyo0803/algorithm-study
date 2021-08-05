//
// Combine files
// Problem: https://www.acmicpc.net/problem/11066
//

#include <iostream>
#define MODE 1 // 0 = Memoization, 1 = Tabulation

using namespace std;

const int MAX_SIZE{500};
const int INF{100000000};
int T, K;
int files[MAX_SIZE + 1];
int dp[MAX_SIZE + 1][MAX_SIZE + 1];
int dp_sum[MAX_SIZE + 1][MAX_SIZE + 1];

#if (MODE == 0)
bool filled[MAX_SIZE + 1][MAX_SIZE + 1];
int memo_method(int i, int j) {
    if (i == j) return 0;
    if (filled[i][j]) return dp[i][j];

    dp[i][j] = INF;
    for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], memo_method(i, k) + memo_method(k + 1, j));
    }
    dp_sum[i][j] = dp_sum[i + 1][j] + files[i];
    dp[i][j] += dp_sum[i][j];
    filled[i][j] = true;
    return dp[i][j];
}
#else
int tabulate_method(int n) {
    for (int r = 2; r <= n; r++) {
        for (int i = 1; i <= n - r + 1; i++) {
            int j = i + r - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            dp_sum[i][j] = dp_sum[i][j - 1] + files[j];
            dp[i][j] += dp_sum[i][j];
        }
    }

    return dp[1][n];
}
#endif

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> T;

#if (MODE == 0)
    cout << "Memoization" << endl;
#else
    cout << "Tabulation" << endl;
#endif
    for (int tc = 0; tc < T; tc++) {
        cin >> K;
        for (int i = 1; i <= K; i++) {
            cin >> files[i];
            dp_sum[i][i] = files[i];
        }
#if (MODE == 0)
        for (int i = 1; i <= K; i++) {
            for (int j = 1; j <= K; j++) {
                filled[i][j] = false;
            }
        }
        cout << memo_method(1, K) << endl;
#else
        cout << tabulate_method(K) << endl;
#endif
    }

    return 0;
}

