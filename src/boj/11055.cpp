//
// Biggest Increasing Subsequence
// Problem: https://www.acmicpc.net/problem/11055
//

#include <iostream>

#define MODE 1 // 0 == memoization, 1 = tabulation

using namespace std;
const int MAX_SIZE{1000};
int N;
int seq[MAX_SIZE + 1];
int dp[MAX_SIZE + 1];

#if (MODE == 0)
int memo_method(int i) {
    if (dp[i]) return dp[i];

    int prev_max{0};
    for (int j = i - 1; j >= 1; j--) {
        if (seq[j] < seq[i]) {
            int res = memo_method(j);
            if (prev_max < res) {
                prev_max = res;
            }
        }
    }
    dp[i] = prev_max + seq[i];
    return dp[i];
}
#else
int tabulate_method(int n) {
    int ans = seq[1];
    for (int i = 2; i <= n; i++) {
        int prev_max{0};
        for (int j = 1; j < i; j++) {
            if (seq[j] < seq[i]) {
                if (prev_max < dp[j]) {
                    prev_max = dp[j];
                }
            }
        }
        dp[i] = prev_max + seq[i];
        if (ans < dp[i]) ans = dp[i];
    }
    return ans;
}
#endif

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> seq[i];
    }
    dp[1] = seq[1];

#if (MODE == 0)
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int res = memo_method(i);
        if (ans < res) ans = res;
    }
    cout << ans;
#else
    cout << tabulate_method(N);
#endif
    return 0;
}
