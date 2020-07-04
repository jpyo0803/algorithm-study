//
// Lan Cable Cutting
// Problem: https://www.acmicpc.net/problem/1654
//

#include <cstdio>
#include <cstdint>
const int MAX{10000};
int K, N, ans{0};
int cables[MAX];

void BinarySearch(uint64_t l, uint64_t r) {
    if (l > r) return;

    uint64_t m = (l + r) / 2;
    uint64_t sum = 0;
    for (int i = 0; i < K; i++) {
        sum += cables[i] / m;
    }
    if (sum >= N) {
        if (ans < m) {
            ans = m;
        }
        BinarySearch(m + 1, r);
    } else if (sum < N) {
        BinarySearch(l, m - 1);
    }
}
int main() {
    scanf("%d%d", &K, &N);
    for (int i = 0; i < K; i++) {
        scanf("%d", &cables[i]);
    }

    BinarySearch(1, ((uint64_t)1 << 31) + 1);
    printf("%d", ans);
    return 0;
}

