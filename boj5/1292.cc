//
// 쉽게 푸는 문제
// Link: https://www.acmicpc.net/problem/1292
//

#include <stdio.h>
#include <math.h>

int A, B;

int SumUpTo(int x) {
	if (x == 0) return 0;
	int n = static_cast<int>((-1.0 + sqrt(1.0 + 8.0 * x)) / 2.0);
	int idx = n * (n + 1) / 2;
	int sum = n * (n + 1) * (2 * n + 1) / 6;
	for (int i = 0; i < x - idx; i++) {
		sum += (n + 1);
	}
	return sum;
}

int Solve(int A, int B) {
	return SumUpTo(B) - SumUpTo(A - 1);
}

int main() {
	scanf("%d%d", &A, &B);
	printf("%d\n", Solve(A, B));
	return 0;
}
