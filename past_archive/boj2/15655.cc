//
// N and M 6
// Problem: https://www.acmicpc.net/problem/15655
//

#include <cstdio>
#include <iostream>

using namespace std;
const int MAX{8};
int N, M;
int nums[MAX];
int chosen[MAX];

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

int partition(int arr[], int l, int r) {
  int i = l;
  int pivot = arr[r];
  for (int j = l; j < r; j++) {
    if (arr[j] < pivot) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[r]);
  return i;
}

void quicksort(int arr[], int l, int r) {
  if (l < r) {
    int p = partition(arr, l, r);
    quicksort(arr, l, p - 1);
    quicksort(arr, p + 1, r);
  }
}

void solve(int nth, int prev_idx) {
  if (nth == M) {
    for (int i = 0; i < M; i++) {
      printf("%d ", chosen[i]);
    }
    printf("\n");
    return;
  }

  for (int i = prev_idx + 1; i < N; i++) {
    chosen[nth] = nums[i];
    solve(nth + 1, i);
  }
};

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
  quicksort(nums, 0, N - 1);

  solve(0, -1);
  return 0;
}
