//
// Floyd
// Problem: https://www.acmicpc.net/problem/11404
//

#include <cstdio>

inline int min(int x, int y) { return x < y ? x : y; }

const int MAX{100};
const int INF{1000000000};
int N, M, a, b, c;
int W[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1];

void Floyd_Warshall() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = W[i][j];
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            W[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        W[a][b] = min(W[a][b], c);
    }

    for (int i = 1; i <= N; i++) W[i][i] = 0;

    Floyd_Warshall();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[i][j] == INF) printf("0 ");
            else printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}

