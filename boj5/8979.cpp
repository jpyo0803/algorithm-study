//
// 올림픽
// Link: https://www.acmicpc.net/problem/8979
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Nation {
	int id, gold, silver, bronze;
	Nation(int i, int g, int s, int b) : id(i), gold(g), silver(s), bronze(b) {}
	bool operator==(const Nation& other) {
		return gold == other.gold && silver == other.silver && bronze == other.bronze;
	}
	bool operator!=(const Nation& other) {
		return !(*this == other);
	}
};

int N, K;

bool Comparator(Nation& x, Nation& y) {
	if (x.gold == y.gold) {
		if (x.silver == y.silver) {
			if (x.bronze == y.bronze) {
				return false;
			} else {
				return x.bronze > y.bronze;
			}
		} else {
			return x.silver > y.silver;
		}
	} else {
		return x.gold > y.gold;
	}
}

int main() {
	vector<Nation> nations;

	scanf("%d%d", &N, &K);
	for (int n = 0; n < N; n++) {
		int id, g, s, b;
		scanf("%d%d%d%d", &id, &g, &s, &b);
		nations.emplace_back(id, g, s, b);
	}

	sort(nations.begin(), nations.end(), Comparator);
	
	int rank = 1;
	int accum = 0;
	Nation* prev;
	for (int i = 0; i < nations.size(); i++) {
		if (i == 0) prev = &nations[i];
		else {
			if (*prev != nations[i]) {
				rank += accum;
				accum = 0;
			}
			prev = &nations[i];
		}

		if (nations[i].id == K) {
			printf("%d\n", rank);
			return 0;
		}
		accum++;
	}

	return 0;
}
