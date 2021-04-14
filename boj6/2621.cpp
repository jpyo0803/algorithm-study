// 카드게임
// https://www.acmicpc.net/problem/2621

#include <iostream>
#include <map>

using namespace std;
map<char, int> color_count;
int number_count[10];

bool AreAllColorsSame() {
	for (auto& e : color_count) {
		if (e.second == 5) return true;
	}
	return false;
}

int IsSequential() {
	for (int i = 1; i <= 5; i++) {
		if (number_count[i] == 1
				&& number_count[i + 1] == 1
				&& number_count[i + 2] == 1
				&& number_count[i + 3] == 1
				&& number_count[i + 4] == 1) return i + 4;
	}
	return -1;
}

int IsSameNumberN(int N, int other_than) {
	for (int i = 1; i <= 9; i++) {
		if (i == other_than) continue;
		if (number_count[i] == N) return i;
	}
	return -1;
}

int GetLargestNumber() {
	for (int i = 9; i >= 1; i--) {
		if (number_count[i] != 0) return i;
	}
	return 0; // should not reach
}

int Min(int x, int y) { return x < y ? x : y; }
int Max(int x, int y) { return x > y ? x : y; }

int Rule1() {
	if (AreAllColorsSame()) {
		int res = IsSequential();
		if (res != -1) {
			return 900 + res;
		}
	}
	return 0;
}

int Rule2() {
	int res = IsSameNumberN(4, -1);
	if (res != -1) return 800 + res;
	return 0;
}

int Rule3() {
	int res1 = IsSameNumberN(3, -1);
	if (res1 != -1) {
		int res2 = IsSameNumberN(2, res1);
		if (res2 != -1) {
			return res1 * 10 + res2 + 700;
		}
		return 0;
	}
	return 0;
}

int Rule4() {
	if (AreAllColorsSame()) {
		int res = GetLargestNumber();
		return res + 600;
	}
	return 0;
}

int Rule5() {
	int res = IsSequential();
	if (res != -1) return res + 500;
	return 0;
}

int Rule6() {
	int res1 = IsSameNumberN(3, -1);
	if (res1 != -1) {
		int res2 = IsSameNumberN(2, res1);
		if (res2 == -1) return res1 + 400;
	}
	return 0;
}

int Rule7() {
	int res1 = IsSameNumberN(2, -1);
	if (res1 != -1) {
		int res2 = IsSameNumberN(2, res1);
		if (res2 != -1) {
			int larger = Max(res1, res2);
			int smaller = Min(res1, res2);
			return larger * 10 + smaller + 300; 
		}
	}
	return 0;
}

int Rule8() {
	int res1 = IsSameNumberN(2, -1);
	if (res1 != -1) {
		int res2 = IsSameNumberN(2, res1);
		if (res2 == -1) return res1 + 200;
	}
	return 0;
}

int Rule9() {
	return GetLargestNumber() + 100;
}

int main() {
	for (int i = 0; i < 5; i++) {
		char color;
		int number;
		cin >> color >> number;
		color_count[color]++;
		number_count[number]++;
	}

	int ans = 0;
	ans = Max(ans, Rule1()); 
	ans = Max(ans, Rule2()); 
	ans = Max(ans, Rule3());
	ans = Max(ans, Rule4());
	ans = Max(ans, Rule5());
	ans = Max(ans, Rule6());
	ans = Max(ans, Rule7());
	ans = Max(ans, Rule8());
	ans = Max(ans, Rule9());

	cout << ans << endl;
	return 0;
}
