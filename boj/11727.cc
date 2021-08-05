//
// 2 x n tiling 2
// Problem : https://www.acmicpc.net/problem/11727
//

#include <iostream>

#define MODE 1 // 0 = memoization, 1 = tabulation
using namespace std;
int N;
int dp[1001];

const int div_mod = 10007;

#if (MODE == 0)
int memo_tiling_2n_2(int i) {
    if (dp[i] != 0) return dp[i];

    if (i == 1) {
        dp[i] = 1;
        return dp[i];
    }
    if (i == 2) {
        dp[i] = 3;
        return dp[i];
    }

    dp[i] = ((memo_tiling_2n_2(i - 1) % div_mod) + (memo_tiling_2n_2(i - 2) * 2) % div_mod) % div_mod;
    return dp[i];
}
#else
int tabulate_tiling_2n_2(int n) {
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= n; i++) {
        dp[i] = ((dp[i - 1] % div_mod) + ((dp[i - 2] * 2) % div_mod)) % div_mod;
    }
    return dp[n];
}
#endif

int main() {
    cin >> N;

#if (MODE == 0)
    cout << memo_tiling_2n_2(N);
#else
    cout << tabulate_tiling_2n_2(N);
#endif
}