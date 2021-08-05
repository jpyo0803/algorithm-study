/*
 * Tiling 3 x n
 * Problem : https://www.acmicpc.net/problem/2133
 */

#include <iostream>

#define MODE 1 // 0 = memoization, 1 = tabulation
using namespace std;
int N;
int dp[31];

#if (MODE == 0)
int memo_tiling_3n(int i) {
    if (i % 2 || i <= 0) return 0;

    if (dp[i] != 0) return dp[i];

    if (i == 2) {
        dp[i] = 3;
        return dp[i];
    }

    dp[i] = memo_tiling_3n(i - 2) * 3;
    for (int k = 0; k <= i - 4; k += 2) {
        dp[i] += memo_tiling_3n(k) * 2;
    }
    dp[i] += 2;
    return dp[i];
}
#else
int tabulate_tiling_3n(int n) {
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for (int k = 0; k <= i - 4; k += 2) {
            dp[i] += dp[k] * 2;
        }
        dp[i] += 2;
    }
    return dp[n];
}
#endif
int main() {
    cin >> N;
#if (MODE == 0)
    cout << memo_tiling_3n(N);
#else
    cout << tabulate_tiling_3n(N);
#endif
    return 0;
}