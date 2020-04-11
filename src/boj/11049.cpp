/*
Matrix Multiplication Order

problem : https://www.acmicpc.net/problem/11049

*/

#include <cstdio> 
#include <iostream>

using namespace std;

#define MODE 1 // Tabulation(Bottom-up) = 1, Memoization(Top-down) = 2

const int max_size = 500;

int mat_dim[max_size + 1][2];
int dp[max_size + 1][max_size + 1];

int N, r, c;

#if (MODE == 1)
int memo_method(int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int min_val = (1 << 30) - 1 + (1 << 30); // = (1 << 31) - 1
    for (int k = i; k < j; k++) {
        int p = mat_dim[i][0] * mat_dim[k][1] * mat_dim[j][1];
        int val = memo_method(i, k) + memo_method(k + 1, j) + p;
        if (val < min_val) {
            min_val = val;
        }
    }
    dp[i][j] = min_val;
    return dp[i][j];
}
#else
void tabulate_method(int N) {
    for (int i = 2; i <= N; i++) { // partition size
        for (int j = 1; j <= N - i + 1; j++) { // partition pos
            int min_val = (1 << 30) - 1 + (1 << 30); // = (1 << 31) - 1
            for (int k = j; k < j + i - 1; k++) {
                int p = mat_dim[j][0] * mat_dim[k][1] * mat_dim[j + i - 1][1];
                int val = dp[j][k] + dp[k + 1][j + i - 1] + p;
                if (val < min_val) {
                    min_val = val;
                }
            }
            dp[j][j + i - 1] = min_val;
        }
    }
}
#endif

int main() {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &r, &c);
        mat_dim[i][0] = r;
        mat_dim[i][1] = c;

        dp[i][i] = 0; // non-trivial, no scalar multiplication necessary
    }
#if (MODE == 1)
    printf("%d", memo_method(1, N));
#else
    tabulate_method(N);
    printf("%d", dp[1][N]);
#endif
    return 0;
}