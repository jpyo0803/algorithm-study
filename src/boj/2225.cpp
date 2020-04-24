//
// Sum Disintegration
// Problem: https://www.acmicpc.net/problem/2225
//

#include <iostream>

#define MODE 0 // 0 = Memoization, 1 = Tabulation

using namespace std;
int N, K;
const int MAX_SIZE{200};
const int DIV_MOD{1000000000};
int dp[MAX_SIZE + 1][MAX_SIZE + 1];

#if (MODE == 0)
bool filled[MAX_SIZE + 1][MAX_SIZE + 1];
int memo_method(int i, int k) {
    if (k == 1) return 1;
    if (filled[i][k]) return dp[i][k];

    for (int j = 0; j <= i; j++) {
        dp[i][k] = ((dp[i][k] % DIV_MOD) + (memo_method(i - j, k - 1) % DIV_MOD) % DIV_MOD);
    }
    filled[i][k] = true;
    return dp[i][k];
}
#else
int tabulate_method(int N, int K) {
    for (int i = 0; i <= N; i++) {
        dp[i][1] = 1;
    }

    for (int k = 2; k <= K; k++) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][k] = ((dp[i][k] % DIV_MOD) + (dp[i - j][k - 1] % DIV_MOD) % DIV_MOD);
            }
        }
    }
    return dp[N][K];
}
#endif
int main() {
    cin >> N >> K;
#if (MODE == 0)
    cout << "Memoization" << endl;
    cout << memo_method(N, K);
#else
    cout << "Tabulation" << endl;
    cout << tabulate_method(N, K);
#endif
    return 0;
}