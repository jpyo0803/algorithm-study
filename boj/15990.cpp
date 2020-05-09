//
// 1, 2, 3 Addtion 5
// Problem: https://www.acmicpc.net/problem/15990
//

#include <cstdio>
#include <iostream>

#define MODE 1 // 0 = Memo, 1 = Tabul

#if (MODE == 1)
#include <vector>
#endif

using namespace std;
const int MAX{100000};
const int MOD{1000000009};
int T, N;
uint32_t dp[MAX + 1][4];

#if (MODE == 0)
bool filled[MAX + 1][4];
uint32_t memo_method(int i, int j) {
    if (i <= 0) return 0;
    if (filled[i][j]) return dp[i][j];

    for (int k = 1; k <= 3; k++) {
        if (j == k) continue;
        dp[i][j] += (memo_method(i - j, k) % MOD);
    }
    dp[i][j] %= MOD;
    filled[i][j] = true;
    return dp[i][j];
}
#else
void tabulate_method(int n) {
    for (int i = 4; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (j == k) continue;
                dp[i][j] += (dp[i - j][k] % MOD);
            }
            dp[i][j] %= MOD;
        }
    }
}
#endif

int main() {
    cin >> T;
    dp[1][1] = dp[2][2] = dp[3][3] = dp[3][2] = dp[3][1] = 1;
#if (MODE == 1)
    vector<int> queries;
    int max_n = 1;
#else
    filled[1][1] = filled[2][2] = filled[3][3] = filled[3][2] = filled[3][1] = true;
#endif
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
#if (MODE == 0)
        uint32_t ans = 0;
        for (int k = 1; k <= 3; k++) {
            ans += (memo_method(N, k) % MOD);
        }
        ans %= MOD;
        printf("%u\n", ans);
#else
        queries.push_back(N);
        if (max_n < N) {
            max_n = N;
        }
#endif
    }
#if (MODE == 1)
    tabulate_method(max_n);
    for (auto query : queries) {
        uint32_t ans = 0;
        for (int k = 1; k <= 3; k++) {
            ans += (dp[query][k] % MOD);
        }
        ans %= MOD;
        printf("%u\n", ans);
    }
#endif

    return 0;
}