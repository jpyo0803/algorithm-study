//
// 지능형 기차
// Link: https://www.acmicpc.net/problem/2455
//

#include <cstdio>

int main() {
	int total = 0;
	int max_val = 0;
	for (int i = 0; i < 4; i++) {
		int out, in;
		scanf("%d%d", &out, &in);
		total -= out;
		total += in;
		max_val = max_val < total ? total : max_val;
	}
	printf("%d\n", max_val);
	return 0;
}
