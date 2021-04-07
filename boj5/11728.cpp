//
// 배열합치기
// Link: https://www.acmicpc.net/problem/11728
//

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
int A[1000000];
int B[1000000];

vector<int> Solve() {
	vector<int> ans;

	sort(A, A + N);
	sort(B, B + M);

	int i, j;
	i = j = 0;

	while (i + j < N + M) {
		if (i < N && j < M) {
			if (A[i] < B[j]) ans.push_back(A[i++]);
			else ans.push_back(B[j++]);
		} else if (i < N) {
			ans.push_back(A[i++]);
		} else {
			ans.push_back(B[j++]);
		}
	}
	return ans;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int n = 0; n < N; n++) scanf("%d", &A[n]);
	for (int m = 0; m < M; m++) scanf("%d", &B[m]);

	auto vec = Solve();
	for (auto e : vec) {
		printf("%d ", e);
	}
	return 0;
}
