//
// Tournament
// Problem: https://www.acmicpc.net/problem/1057
//

#include <cstdio>
int N, kim, lim;
int main() {
    scanf("%d%d%d", &N, &kim, &lim);
    int bf = kim < lim ? kim : lim;
    int af = (bf == kim) ? lim : kim;

    int round{0};
    while (af != bf) {
        bf = (bf % 2) ? (bf + 1) / 2 : bf / 2;
        af = (af % 2) ? (af + 1) / 2 : af / 2;
        round += 1;
    }
    if (round) printf("%d", round);
    else printf("-1");

    return 0;
}

