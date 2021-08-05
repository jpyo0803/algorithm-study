//
// Pinary Number
// Problem : https://www.acmicpc.net/problem/2193
//

#include <iostream>

#define MODE 0 // 0 = memoization, 1 = tabulation

using namespace std;
int N;
uint64_t dp[91][2]; // ends with 0, ends with 1

#if (MODE == 0)
bool filled[91][2];
uint64_t memo_pinary_number(int i, bool binary) {
    if (filled[i][binary]) return dp[i][binary];

    if (i == 1) {
        dp[i][binary] = binary;
        filled[i][binary] = true;
        return dp[i][binary];
    }

    if (binary) {
        dp[i][binary] = memo_pinary_number(i - 1, !binary);
    } else {
        dp[i][binary] = memo_pinary_number(i - 1, binary) + memo_pinary_number(i - 1, !binary);
    }
    filled[i][binary] = true;
    return dp[i][binary];
}
#else
uint64_t tabulate_pinary_number(int n) {
    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    return dp[n][0] + dp[n][1];
}
#endif
int main() {
    cin >> N;
#if (MODE == 0)
    cout << memo_pinary_number(N, 0) + memo_pinary_number(N, 1);
#else
    cout << tabulate_pinary_number(N);
#endif
}

