//
// First Year
// Problem: https://www.acmicpc.net/problem/5557
//

#include <iostream>

#define MODE 0 // 0 = memoization, 1 = tabulation

using namespace std;
const int MAX{100};
int nums[MAX + 1];
int N;
uint64_t dp[MAX + 1][21];

#if (MODE == 0)
bool filled[MAX + 1][21];
uint64_t memo_method(int i, int j) {
    if (i == 1) {
        if (j == nums[1]) return 1;
        else return 0;
    }
    if (j < 0 || j > 20) return 0;

    if (filled[i][j]) return dp[i][j];

    dp[i][j] += memo_method(i - 1, j + nums[i]) + memo_method(i - 1, j - nums[i]);
    filled[i][j] = true;
    return dp[i][j];
}
#else
uint64_t tabulate_method(int n) {
    dp[1][nums[1]] = 1;
    for (int i = 2; i < n; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - nums[i] >= 0) {
                dp[i][j] += dp[i - 1][j - nums[i]];
            }
            if (j + nums[i] <= 20) {
                dp[i][j] += dp[i - 1][j + nums[i]];
            }
        }
    }

    return dp[n - 1][nums[n]];
}
#endif
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> nums[i];
#if (MODE == 0)
    cout << memo_method(N - 1, nums[N]);
#else
    cout << tabulate_method(N);
#endif
    return 0;
}