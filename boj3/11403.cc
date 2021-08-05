//
// Path Finding
// Problem: https://www.acmicpc.net/problem/11403
//

#include <cstdio>

const int MAX{101};
int N;
bool adj_mat[MAX][MAX];

void FW() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (adj_mat[i][k] && adj_mat[k][j]) {
                    adj_mat[i][j] = true;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &adj_mat[i][j]);
        }
    }
    FW();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
