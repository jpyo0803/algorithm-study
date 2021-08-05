//
// Path on Grid
// Problem: https://www.youtube.com/watch?v=CYzWJO54Ch8
//

#include <cstdio>
#include <cmath>

#define MODE 1 // memo_method = 1, tabulate_method = 2

const int MAX{15};
int N, M, K;
int dp[MAX + 1][MAX + 1];

#if (MODE == 1)
bool filled[MAX + 1][MAX + 1];

int memo_method(int r, int c, int sr, int sc) {
    if (r == sr - 1 || c == sc - 1) return 0;
    if (r == sr && c == sc) return 1;
    if (filled[r][c]) return dp[r][c];

    dp[r][c] = memo_method(r - 1, c, sr, sc) + memo_method(r, c - 1, sr, sc);
    filled[r][c] = true;
    return dp[r][c];
}

#else
int tabulate_method(int sr, int sc, int er, int ec, int sv) {
    dp[sr][sc] = sv;
    dp[sr - 1][sc] = dp[sr][sc - 1] = 0;

    for (int i = sr; i <= er; i++) {
        for (int j = sc; j <= ec; j++) {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[er][ec];
}
#endif


int main() {
    scanf("%d%d%d", &N, &M, &K); // 3, 5, 8
    int ans;
    if (K != 0) {
        int kr = ceil((double) K / M);
        int kc = K % M == 0 ? M : K % M;
#if (MODE == 1)
        ans = memo_method(kr, kc, 1, 1) * memo_method(N, M, kr, kc);
#else
        ans = tabulate_method(1, 1, kr, kc, 1) * tabulate_method(kr, kc, N, M, 1);
#endif
    } else {
#if (MODE == 1)
        ans = memo_method(N, M, 1, 1);
#else
        ans = tabulate_method(1, 1, N, M, 1);
#endif
    }
    printf("%d", ans);

    return 0;
}


