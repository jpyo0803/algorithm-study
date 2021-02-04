//
// 새
// Link: https://www.acmicpc.net/problem/1568
//

#include <cstdio>

int N;

int main() {
	scanf("%d", &N);
	
	int seconds = 0;
	int k = 1;
	while (N > 0) {
		N -= k++;
		seconds++;
		if (k > N) k = 1;
	}
	printf("%d\n", seconds);
	return 0;
}
