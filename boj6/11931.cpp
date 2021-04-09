//
// 수정렬하기4
// Link: https://www.acmicpc.net/problem/11931
//

#include <stdio.h>

using namespace std;

int N;
int arr[1000000];
int working_arr[1000000];


void Mergesort(int left, int right) {
	if (left == right) {
		working_arr[left] = arr[left];
		return;
	}
	int mid = (left + right) / 2;
	Mergesort(left, mid);
	Mergesort(mid + 1, right);

	int i, j, k;
	i = k = left;
	j = mid + 1;
	while (i <= mid && j <= right) {
		if (working_arr[i] < working_arr[j]) arr[k++] = working_arr[j++];
		else arr[k++] = working_arr[i++];
	}

	while (i <= mid) arr[k++] = working_arr[i++];
	while (j <= right) arr[k++] = working_arr[j++];
	for (int i = left; i <= right; i++) working_arr[i] = arr[i];
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", &arr[n]);
	Mergesort(0, N - 1);
	for (int n = 0; n < N; n++) printf("%d\n", arr[n]);
	return 0;
}
