//
// Jump
// Problem: https://www.acmicpc.net/problem/1890
//

#include <iostream>

#define MODE 1 // 0 = Memoization, 1 = Tabulation

using namespace std;
const int MAX_SIZE{100};
int N;
int field[MAX_SIZE + 1][MAX_SIZE + 1];
uint64_t dp[MAX_SIZE + 1][MAX_SIZE + 1];

#if (MODE == 0)
bool filled[MAX_SIZE + 1][MAX_SIZE + 1];
uint64_t memo_method(int i, int j) {
    if (i == 1 && j == 1) return 1;
    if (filled[i][j]) return dp[i][j];

    for (int k = i - 1; k >= 1; k--) {
        if (i == k + field[k][j]) {
            dp[i][j] += memo_method(k, j);
        }
    }
    for (int k = j - 1; k >= 1; k--) {
        if (j == k + field[i][k]) {
            dp[i][j] += memo_method(i, k);
        }
    }
    filled[i][j] = true;
    return dp[i][j];
}
#else
uint64_t tabulate_method(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) dp[1][1] = 1;
            if (i == n && j == n) return dp[n][n];

            if (i + field[i][j] <= N) {
                dp[i + field[i][j]][j] += dp[i][j];
            }
            if (j + field[i][j] <= N) {
                dp[i][j + field[i][j]] += dp[i][j];
            }
        }
    }
}
#endif

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> field[i][j];
        }
    }
#if (MODE == 0)
    cout << "Memoization" << endl;
    cout << memo_method(N, N);
#else
    cout << "Tabulation" << endl;
    cout << tabulate_method(N);
#endif
    return 0;
}