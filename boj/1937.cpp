//
// Panda the greedy one
// Problem: https://www.acmicpc.net/problem/1937
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define MODE 0 // 0 = Memoization, 1 = Tabulation

const int MAX_SIZE{500};
int N;
int forest[MAX_SIZE + 1][MAX_SIZE + 1];
int dp[MAX_SIZE + 1][MAX_SIZE + 1];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class tuple {
public:
    tuple(int _key, int _r, int _c) : key(_key), r(_r), c(_c) {}
    int key;
    int r, c;
};

std::vector<tuple> orders;

bool cmpr(tuple a, tuple b) {
    return a.key < b.key;
}

#if (MODE == 0)
bool filled[MAX_SIZE + 1][MAX_SIZE + 1];
int memo_method(int i, int j) {
    if (filled[i][j]) return dp[i][j];

    int adj_max = 0;
    for (int k = 0; k < 4; k++) {
        int ni{i + d[k][0]};
        int nj{j + d[k][1]};

        if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
            if (forest[ni][nj] < forest[i][j]) {
                int ret = memo_method(ni, nj);
                if (adj_max < ret) {
                    adj_max = ret;
                }
            }
        }
    }
    dp[i][j] = adj_max + 1;
    filled[i][j] = true;
    return dp[i][j];
}
#else
int tabulation(int n, const std::vector<tuple>& vec) {
    int ans = 0;
    for (auto it : vec) {
        int adj_max = 0;
        for (int k = 0; k < 4; k++) {
            int ni{it.r + d[k][0]};
            int nj{it.c + d[k][1]};

            if (ni >= 1 && ni <= n && nj >= 1 && nj <= n) {
                if (forest[ni][nj] < forest[it.r][it.c]) {
                    if (adj_max < dp[ni][nj]) {
                        adj_max = dp[ni][nj];
                    }
                }
            }
        }
        dp[it.r][it.c] = adj_max + 1;
        if (ans < dp[it.r][it.c]) {
            ans = dp[it.r][it.c];
        }
    }
    return ans;
}
#endif
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &forest[i][j]);
#if (MODE == 1)
            orders.emplace_back(forest[i][j], i, j);
#endif
        }
    }

#if (MODE == 0)
    printf("Memoization\n");
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int ret = memo_method(i, j);
            if (ans < ret) {
                ans = ret;
            }
        }
    }
    printf("%d", ans);
#else
    printf("Tabulation\n");
    sort(orders.begin(), orders.end(), cmpr);
    printf("%d", tabulation(N, orders));
#endif
    return 0;
}