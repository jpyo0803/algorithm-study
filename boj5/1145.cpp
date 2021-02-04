//
// 적어도 대부분의 배수
// Link: https://www.acmicpc.net/problem/1145
//

#include <cstdio>

using namespace std;

int nums[5];

int Gcd(int a, int b) {
	if (a < b) {
		int tmp = a;
	  a = b;
		b = tmp;
	}
	if (a % b == 0) return b;
	return Gcd(b, a % b);
}

int Lcm(int a, int b) {
	return a * b / Gcd(a, b);
}

int selected[3];
int ans = 987654321;

void Comb(int nth) {
	if (nth >= 3) {
		int lcm = 1;
		for (int i = 0; i < nth; i++) {
			lcm = Lcm(lcm, nums[selected[i]]);
		}
		ans = lcm < ans ? lcm : ans;
		return;
	}	

	int base = nth == 0 ? 0 : selected[nth - 1] + 1;
	for (int i = base; i < 5; i++) {
		selected[nth] = i;
		Comb(nth + 1);
	}
}

int main() {
	for (int i = 0; i < 5; i++) scanf("%d", &nums[i]);
	Comb(0);
	printf("%d\n", ans);
	return 0;
}
