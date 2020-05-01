//
// Is palindrome?
// Problem: https://www.acmicpc.net/problem/10942
//

#include <cstdio>

#define MODE 1 // 0 = Memoization, 1 = Tabulation

const int MAX_SIZE{2000};
int N, M, S, E;
int nums[MAX_SIZE + 1];
bool dp[MAX_SIZE + 1][MAX_SIZE + 1];

#if (MODE == 0)
bool filled[MAX_SIZE + 1][MAX_SIZE + 1];
bool memo_method(int i, int j) {
    if (i == j) return true;
    if (i + 1 == j) return (nums[i] == nums[j]);
    if (filled[i][j]) return dp[i][j];

    dp[i][j] = false;
    if (memo_method(i + 1, j - 1)) {
        dp[i][j] = (nums[i] == nums[j]);
    }
    filled[i][j] = true;
    return dp[i][j];
}
#else
void tabulate_method(int n) {
    for (int i = 1; i <= n; i++) dp[i][i] = true;
    for (int i = 1; i <= n - 1; i++) dp[i][i + 1] = (nums[i] == nums[i + 1]);

    for (int k = 3; k <= n; k++) {
        for (int i = 1; i <= n - k + 1; i++) {
            int j = i + k - 1;
            if (dp[i + 1][j - 1]) {
                dp[i][j] = (nums[i] == nums[j]);
            }
        }
    }
}
#endif

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &M);
#if (MODE == 0)
    printf("Memoization\n");
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &S, &E);
        printf("%d\n", memo_method(S, E));
    }
#else
    printf("Tabulation\n");
    tabulate_method(N);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &S, &E);
        printf("%d\n", dp[S][E]);
    }
#endif
    return 0;
}

