//
// 트로피 진열
// Link: https://www.acmicpc.net/problem/1668
//

#include <cstdio>

int heights[50];
int N;

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", &heights[n]);
	}
	
	int seen = 1;
	int prev_max = heights[0];
	for (int i = 1; i < N; i++) {
		if (heights[i] > prev_max) {
			seen++;
			prev_max = heights[i];
		}
	}
	printf("%d\n", seen);

	seen = 1;
	prev_max = heights[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (heights[i] > prev_max) {
			seen++;
			prev_max = heights[i];
		}
	}
	printf("%d\n", seen);
	return 0;
}
