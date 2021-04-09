//
// N번째 큰수
// Link: https://www.acmicpc.net/problem/2693
//

#include <stdio.h>

int T, x;

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int first, second, third;
		first = second = third = 0;
		for (int i = 0; i < 10; i++) {
			scanf("%d", &x);
			if (x > first) {
				third = second;
				second = first;
				first = x;
			} else if (x > second) {
				third = second;
				second = x;
			} else if (x > third) {
				third = x;
			}
		}
		printf("%d\n", third);
	}
	return 0;
}
