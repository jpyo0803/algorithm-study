//
// 2진수 8진수
// Link: https://www.acmicpc.net/problem/1373
//

#include <cstdio>
#include <string.h>

using namespace std;

char input[1000010];
char ans[500000];

int BinToOct(int pos, int count) {
	int base = 1;
	int sum = 0;
	for (int i = pos + count - 1; i >= pos; i--) {
		sum += (input[i] - '0') * base;
		base *= 2;
	}
	return sum;
}

int main() {
	scanf("%s", input);
	
	int i = strlen(input) - 3;
	int j = 0;
	while (i > -1) {
		ans[j++] = BinToOct(i, 3) + '0';
		i -= 3;
	}

	if (i != -3) {
		ans[j++] = BinToOct(0, 3 + i) + '0';
	}
	for (int x = j - 1; x >= 0; x--) {
		putchar(ans[x]);
	}
	putchar('\n');

	return 0;
}
