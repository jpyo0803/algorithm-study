//
// 좌표 압축
// Link: https://www.acmicpc.net/problem/18870
//

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, x;

int nums[1000000];
vector<int> sorted;

int BinarySearch(int key, int l, int r) {
	int mid = (l + r) / 2;
	if (sorted[mid] < key) {
		return BinarySearch(key, mid + 1, r);
	} else if (sorted[mid] > key) {
		return BinarySearch(key, l, mid - 1);
	} else {
		return mid;
	}
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", &x);
		nums[n] = x;
		sorted.push_back(x);		
	}

	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	for (int i = 0; i < N; i++) {
		printf("%d ", BinarySearch(nums[i], 0, sorted.size() - 1));
	}
	printf("\n");
	return 0;
}	
