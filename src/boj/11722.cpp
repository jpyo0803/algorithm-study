//
// Longest Decreasing Subsequence
// Problem: https://www.acmicpc.net/problem/11722
//

#include <iostream>

#define MODE 0 // 0 = Memoization, 1 = Tabulation

using namespace std;
const int MAX_SIZE{1000};
int N;
int seq[MAX_SIZE + 1];
int dp[MAX_SIZE + 1];

#if (MODE == 0)
int memo_method(int i) {
    if (dp[i]) return dp[i];

    int prev_max = 0;
    for (int j = 1; j < i; j++) {
        if (seq[i] < seq[j]) {
            int res = memo_method(j);
            if (prev_max < res) {
                prev_max = res;
            }
        }
    }
    dp[i] = prev_max + 1;
    return dp[i];
}
#else
int tabulate_method(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int prev_max = 0;
        for (int j = 1; j < i; j++) {
            if (seq[i] < seq[j]) {
                if (prev_max < dp[j]) {
                    prev_max = dp[j];
                }
            }
        }
        dp[i] = prev_max + 1;
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    return ans;
}
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> seq[i];
    }

#if (MODE == 0)
    cout << "Memoization" << endl;
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        int res = memo_method(i);
        if (ans < res) {
            ans = res;
        }
    }
    cout << ans;
#else
    cout << "Tabulation" << endl;
    cout << tabulate_method(N);
#endif

    return 0;
}