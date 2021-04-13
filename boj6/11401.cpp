//
// 이항계수 3
// Link: https://www.acmicpc.net/problem/11401
//

#include <stdio.h>
#include <inttypes.h>

constexpr int64_t kMod = 1000000007;
int count = 0;
int64_t Pow(int64_t base, int exp) {
	if (exp == 1) return base;
	int64_t res = Pow(base, exp / 2);
	res = (res * res) % kMod;
	if (exp % 2) {
		res *= base;
		res %= kMod;
	}
	return res;
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	int64_t A = 1, B = 1;
	for (int64_t i = N; i >= N - K + 1; i--) {
		A *= i;
		A %= kMod;
	}

	for (int64_t i = 2; i <= K; i++) {
		B *= i;
		B %= kMod;
	}

	int64_t ans = (A * Pow(B, kMod - 2)) % kMod;
	printf("%" PRId64 "\n", ans);

	return 0;
}
