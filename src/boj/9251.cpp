/*
* LCS
* Problem: https://www.acmicpc.net/problem/9251
*/

#include <iostream>

#define MODE 1 // 0 = memoization, 1 = tabulation

using namespace std;

const int max_size = 1000;
int dp[max_size + 1][max_size + 1];

string X, Y;
int len_x, len_y;

int maximum(int x, int y) {
    return (x < y) ? y : x;
}

#if (MODE == 0)
int memo_method(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    if (i == 0 || j == 0) {
        dp[i][j] = 0;
        return dp[i][j];
    }

    if (X[i - 1] == Y[j - 1]) {
        dp[i][j] = memo_method(i - 1, j - 1) + 1;
    } else {
        dp[i][j] = maximum(memo_method(i, j - 1), memo_method(i - 1, j));
    }
    return dp[i][j];
}
#else
int tabulate_method(int max_i, int max_j) {
    for (int i = 1; i <= max_i; i++) {
        for (int j = 1; j <= max_j; j++) {
            if (X[i - 1] == Y[j - 1]) { // left up
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[max_i][max_j];
}
#endif

int main() {
    cin >> X >> Y;
    len_x = X.length();
    len_y = Y.length();

#if (MODE == 0)
    for (int i = 1; i <= len_x; i++) {
        for (int j = 1; j <= len_y; j++) {
            dp[i][j] = -1;
        }
    }
    cout << memo_method(len_x, len_y);
#else
    cout << tabulate_method(len_x, len_y);
#endif
    return 0;
}