//
// Resignation
// Problem: https://www.acmicpc.net/problem/14501
//

#include <iostream>

#define MODE 0 // 0 = memoization, 1 = tabulation
using namespace std;

int N;
int dp[16];
int T_i[16];
int P_i[16];

#if (MODE == 0)
bool filled[16];
int memo_method(int i) {
    if (filled[i]) return dp[i];

    for (int j = i - 1; j >= 0; j--) {
        int loc_max = memo_method(j);
        if (j + T_i[j] <= i) {
            loc_max += P_i[j];
        }
        if (dp[i] < loc_max) {
            dp[i] = loc_max;
        }
    }
    filled[i] = true;
    return dp[i];
}
#else
int tabulate_method(int n) {
    for (int i = 0; i < n; i++) {
        int past_max = (i - 1 >= 0) ? dp[i - 1] : 0;
        if (dp[i + T_i[i] - 1] < past_max + P_i[i]) {
            dp[i + T_i[i] - 1] = past_max + P_i[i];
        }
        if (i - 1 >= 0 && dp[i] < dp[i - 1]) {
            dp[i] = dp[i - 1];
        }
    }
    return dp[n - 1];
}
#endif
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T_i[i] >> P_i[i];
    }
#if (MODE == 0)
    cout << memo_method(N);
#else
    cout << tabulate_method(N);
#endif
    return 0;
}