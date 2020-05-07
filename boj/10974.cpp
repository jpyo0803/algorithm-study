//
// All sequence
// Problem: https://www.acmicpc.net/problem/10974
//

#include <cstdio>

using namespace std;
const int MAX_SIZE{8};
int N;
int seq[MAX_SIZE];
bool used[MAX_SIZE + 1];

void perm(int num_filled) {
    if (num_filled == N) {
        for (int i = 0; i < N; i++) {
            printf("%d ", seq[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            used[i] = true;
            seq[num_filled] = i;
            perm(num_filled + 1);
            used[i] = false;
        }
    }
}
int main() {
    scanf("%d", &N);
    perm(0);
    return 0;
}

