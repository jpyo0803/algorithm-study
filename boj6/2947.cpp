//
// 나무조각
// Link: https://www.acmicpc.net/problem/2947
//

#include <stdio.h>

int arr[5];

void Swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void Print(int arr[]) { 
	for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
	printf("\n");
}

bool InOrder(int arr[]) {
	for (int i = 0; i < 4; i++) {
		if (arr[i] + 1 != arr[i + 1]) return false;
	}
	return true;
}

void DoShuffle(int arr[]) {
	for (int i = 0; i < 4; i++) {
		if (arr[i] > arr[i + 1]) {
			Swap(arr[i], arr[i + 1]);
			Print(arr);
		}
	}
}

void Solve(int arr[]) {
	do {
		DoShuffle(arr);
	} while (!InOrder(arr));
}

int main() {
	for (int i = 0; i < 5; i++) scanf("%d", &arr[i]);
	Solve(arr);
	return 0;
}
