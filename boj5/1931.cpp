//
// 회의실 배정
// Link: https://www.acmicpc.net/problem/1931
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int N;
vector<pair<uint32_t, uint32_t>> meetings;

bool Compare(pair<uint32_t, uint32_t>& x, pair<uint32_t, uint32_t>& y) { 
	if (x.second == y.second) return x.first < y.first;
	return x.second < y.second;
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		uint32_t a, b;
		scanf("%u%u", &a, &b);
		meetings.emplace_back(a, b);
	}
	sort(meetings.begin(), meetings.end(), Compare);

	uint32_t last_end = 0;
	int answer = 0;
	for (auto& e : meetings) {
		if (last_end <= e.first) {
			answer++;
			last_end = e.second;
		}
	}

	printf("%d\n", answer);
	
	return 0;
}
